#include <bits/stdc++.h>

using namespace std;

struct Trie {
    struct Node {
        vector<unique_ptr<Node>> child;
        int cnt = 0;
        Node() : cnt(0), child(2) {
        }
    };

    unique_ptr<Node> head;

    Trie() : head(make_unique<Node>()) {
    }

    void insert(int val) {
        Node* cur = head.get();
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            ++cur->cnt;
            if (!cur->child[v]) {
                cur->child[v] = make_unique<Node>();
            }
            cur = cur->child[v].get();
        }
        ++cur->cnt;
    }

    void erase(int val) {
        Node* cur = head.get();
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            --cur->cnt;
            cur = cur->child[v].get();
        }
        --cur->cnt;
    }

    int getMaxXOR(int val) {
        Node* cur = head.get();
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            bool w = !v;
            if (cur->child[w] && cur->child[w]->cnt != 0) {
                cur = cur->child[w].get();
                res += (1 << i);
            } else {
                if (!cur->child[v]) {
                    cur->child[v] = make_unique<Node>();
                }
                cur = cur->child[v].get();
            }
        }
        return res;
    }

    int getMinXOR(int val) {
        Node* cur = head.get();
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            bool v = val & (1 << i);
            if (cur->child[v] && cur->child[v]->cnt != 0) {
                cur = cur->child[v].get();
            } else {
                bool w = !v;
                if (!cur->child[w]) {
                    cur->child[w] = make_unique<Node>();
                }
                cur = cur->child[w].get();
                res += (1 << i);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    Trie trie;
    int val = 0;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
        val ^= b[i];
        trie.insert(val);
    }
    for (int st = 0; st < n; st++) {
        int mn = 0, mx = n - 1;
        if (mn == st) {
            mn++;
        }
        if (mx == st) {
            mx--;
        }
        if (trie.getMaxXOR(st) == mx && trie.getMinXOR(st) == mn) {
            vector<int> a(n);
            a[0] = st;
            for (int i = 1; i < n; i++) {
                a[i] = (b[i - 1] ^ a[i - 1]);
            }
            bool valid = true;
            vector<int> cnt(n);
            for (int i = 0; i < n; i++) {
                if (a[i] >= n) {
                    valid = false;
                    break;
                }
                if (++cnt[a[i]] > 1) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                continue; 
            }
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
            return 0;
        }
    }
    assert(false);

    return 0;
}