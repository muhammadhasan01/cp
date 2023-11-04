#include <bits/stdc++.h>

using namespace std;

struct Trie {
    struct Node {
        Node *child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node *head;

    Trie() {
        head = new Node();
    }

    void insert(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            ++cur->cnt;
            if (cur->child[v] == NULL) {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
        }
        ++cur->cnt;
    }

    void erase(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            --cur->cnt;
            cur = cur->child[v];
        }
        --cur->cnt;
    }

    int getMaxXOR(int val) {
        Node *cur = head;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            bool w = !v;
            if (cur->child[w] != NULL && cur->child[w]->cnt != 0) {
                cur = cur->child[w];
                res += (1 << i);
                continue;
            }
            if (cur->child[v] == NULL) {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
        }
        return res;
    }
};

void solve() {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    vector<int> a(len);
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }
    Trie trie;
    for (int i = 0; i < len; i++) {
        trie.insert(a[i]);
    }
    for (int i = 0; i < len; i++) {
        int val = trie.getMaxXOR(a[i]);
        if (val == r) {
            cout << a[i] << '\n';
            return;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}