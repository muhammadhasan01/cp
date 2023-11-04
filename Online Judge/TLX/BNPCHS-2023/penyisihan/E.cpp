#include <bits/stdc++.h>

using namespace std;

struct Trie {
    struct Node {
        Node *child[26];
        bool leaf;
        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            leaf = false;
        }
    };

    Node *head;

    Trie() {
        head = new Node();
        for (int i = 0; i < 26; i++) {
            head->child[i] = new Node();
        }
    }

    void insert(string& s) {
        Node* cur = head;
        for (char cc : s) {
            int num = cc - 'a';
            if (cur->child[num] == NULL) {
                cur->child[num] = new Node();
            }
            cur = cur->child[num];
        }
        cur->leaf = true;
    }

    int simulate(string& s) {
        int ret = 0;
        Node* cur = head;
        for (char cc : s) {
            int num = cc - 'a';
            cur = cur->child[num];
            if (cur == NULL) {
                cur = head->child[num];
            }
            if (cur->leaf) {
                ++ret;
                cur = head;
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    Trie trie;
    for (int i = 0; i < m; i++) {
        string p;
        cin >> p;
        trie.insert(p);
    }
    cout << trie.simulate(s) << '\n';
    
    return 0;
}