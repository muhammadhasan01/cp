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
            bool v = !(val & (1 << i));
            if (cur->child[v] != NULL && cur->child[v]->cnt != 0) {
                cur = cur->child[v];
                res |= (1 << i);
            } else {
                if (cur->child[(v ^ 1)] == NULL) {
                    cur->child[(v ^ 1)] = new Node();
                }
                cur = cur->child[(v ^ 1)];
            }
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Trie trie;
    trie.insert(a[0]);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        a[i] ^= a[i - 1];
        mx = max(mx, trie.getMaxXOR(a[i]));
        trie.insert(a[i]);
    }
    cout << mx << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Trie trie;
    trie.insert(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}