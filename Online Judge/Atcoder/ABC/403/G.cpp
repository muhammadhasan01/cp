#include <bits/stdc++.h>

using namespace std;

const int M = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int key, pr;
    Node *l, *r;
    int sz;
    long long sumOdd, sumEven;
    Node(int _key) {
        key = _key;
        pr = (int) (rng() ^ (rng() << 15));
        l = r = nullptr;
        sz = 1;
        sumOdd = _key;
        sumEven = 0;
    }
};

void pull(Node* t) {
    if (!t) {
        return;
    }
    int szL = t->l ? t->l->sz : 0;
    int szR = t->r ? t->r->sz : 0;
    bool isRootOdd = ((szL + 1) & 1);
    long long o = isRootOdd ? t->key : 0;
    long long e = isRootOdd ? 0 : t->key;
    if (t->l) {
        o += t->l->sumOdd;
        e += t->l->sumEven;
    }
    if (t->r) {
        if (isRootOdd) {
            o += t->r->sumEven;
            e += t->r->sumOdd;
        } else {
            o += t->r->sumOdd;
            e += t->r->sumEven;
        }
    }
    t->sz = szL + 1 + szR;
    t->sumOdd = o;
    t->sumEven = e;
}

void split(Node* t, int key, Node*& l, Node*& r) {
    if (!t) {
        l = r = NULL;
    } else if (t->key < key) {
        split(t->r, key, t->r, r);
        l = t;
        pull(l);
    } else {
        split(t->l, key, l, t->l);
        r = t;
        pull(r);
    }
}

Node* merge(Node* a, Node* b) {
    if (!a || !b) {
        return a ? a : b;
    }
    if (a->pr > b->pr) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;
    Node* root = NULL;
    long long z = 0;
    for (int i = 1; i <= Q; i++) {
        long long y;
        cin >> y;
        int x = int(((y + z) % M) + 1);
        Node *L, *R;
        split(root, x, L, R);
        root = merge(merge(L, new Node(x)), R);
        z = root->sumOdd;
        cout << z << '\n';
    }

    return 0;
}
