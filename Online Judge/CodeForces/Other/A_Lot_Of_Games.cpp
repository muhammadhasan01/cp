#include <bits/stdc++.h>
using namespace std;
typedef pair<bool, bool> pbb;

const int N = 1e5 + 5;
int n, k;
int c;

struct Trie {
    struct Node {
        Node* child[30];
        Node() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
        }
    };

    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* cur = root;
        for (auto e : s) {
            short int k = e - 'a';
            if (cur -> child[k] == NULL) {
                cur -> child[k] = new Node();
            }
            cur = cur -> child[k];
        }
    }

    pbb dfs(Node* u) {
        pbb ret = {false, false};
        bool leaf = true;
        for (int i = 0; i < 26; i++) {
            if (u -> child[i] != NULL) {
                pbb t = dfs(u -> child[i]);
                ret.first |= (!t.first);
                ret.second |= (!t.second);
                leaf = false;
            }
        }
        if (leaf) {
            ret = {false, true};
        }
        return ret;
    }

    void answer() {
        Node* cur = root;
        pbb gt = dfs(cur);
        if (!gt.first) {
            cout << "Second" << '\n';
        } else if (gt.first && gt.second) {
            cout << "First" << '\n';
        } else if (gt.first && !gt.second) {
            cout << (k % 2 == 1 ? "First" : "Second") << '\n';
        }
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    Trie trie;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    trie.answer();

    return 0;
}
