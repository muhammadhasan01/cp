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
 
    int getMinXOR(int val) {
        Node *cur = head;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            if (cur->child[v] != NULL && cur->child[v]->cnt != 0) {
                cur = cur->child[v];
                continue;
            }
            bool w = !v;
            if (cur->child[w] == NULL) {
                cur->child[w] = new Node();
            }
            cur = cur->child[w];
            res += (1 << i);
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