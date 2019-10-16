#include<bits/stdc++.h>
using namespace std;

int q;

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
            bool bit = val & (1 << i);
            ++cur -> cnt;
            if (cur -> child[bit] == NULL) {
                cur -> child[bit] = new Node();
            }
            cur = cur -> child[bit];
        }
        ++cur -> cnt;
    }

    void erase(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool bit = val & (1 << i);
            --cur -> cnt;
            cur = cur -> child[bit];
        }
        --cur -> cnt;
    }

    int getMaxXOR(int val) {
        Node *cur = head;
        int ret = 0;
        for (int i = 30; i >= 0; i--) {
            bool bit = val & (1 << i);
            bit ^= 1;
            if (cur -> child[bit] != NULL && cur -> child[bit] -> cnt > 0) {
                cur = cur -> child[bit];
                ret += (1 << i);
            } else if (cur -> child[bit ^ 1] != NULL){
                cur = cur -> child[bit ^ 1];
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    Trie trie;
    trie.insert(0);
    while (q--) {
        char t;
        int x;
        cin >> t >> x;
        if (t == '+') {
            trie.insert(x);
        } else if (t == '-') {
            trie.erase(x);
        } else if (t == '?') {
            cout << trie.getMaxXOR(x) << '\n';
        }
     }

    return 0;
}
