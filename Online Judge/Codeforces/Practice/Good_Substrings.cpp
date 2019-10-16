#include <bits/stdc++.h>
using namespace std;

string a, b;
int n, k;
int ans;

struct Trie {
    struct Node {
        Node *child[26];
        Node() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
        }
    };

    Node *root;
    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node *cur = root;
        int cnt = 0;
        for (int i = x; i < n; i++) {
            int pos = a[i] - 'a';
            if (b[pos] == '0' && ++cnt > k) break;
            if (cur -> child[pos] == NULL) {
                cur -> child[pos] = new Node();
                ans++;
            }
            cur = cur -> child[pos];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> k;
    n = a.length();
    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.insert(i);
    }
    cout << ans << '\n';

    return 0;
}
