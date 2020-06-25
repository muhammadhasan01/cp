#include <bits/stdc++.h>

using namespace std;

int q;
int n;

struct Trie {
    struct Node {
        Node* child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };
    
    Node* head;

    Trie() {
        head = new Node();
    }

    void insert(int val) {
        Node* cur = head;
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
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            --cur->cnt;
            cur = cur->child[v];
        }
        --cur->cnt;
    }

    int getAnswer(int val, int maks) {
        int ret = 0;
        Node* cur = head;
        bool ok = true;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            bool b = maks & (1 << i);
            if (b) {
                bool w = (v ^ 1);
                if (cur->child[w] == NULL) {
                    ok = false;
                    break;
                }
                cur = cur->child[w];
            } else {
                bool w = (v ^ 1);
                if (cur->child[w] != NULL) ret += cur->child[w]->cnt;
                if (cur->child[v] == NULL) {
                    ok = false;
                    break;
                }
                cur = cur->child[v];
            }
        }
        if (ok) ret += cur->cnt;
        return n - ret;
    }
};

Trie trie;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    cin >> q;
    int tp, x, y;
    while (q--) {
        cin >> tp;
        if (tp == 1) {
            cin >> x;
            trie.insert(x);
            ++n;
        } else if (tp == 2) {
            cin >> x;
            trie.erase(x);
            --n;
        } else if (tp == 3) {
            cin >> x >> y;
            cout << trie.getAnswer(x, y) << '\n';
        }
    }

    return 0;
}