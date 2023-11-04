#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int K = 30;

struct Trie {
    struct Node {
        Node *child[2];
        int dp[2];
        Node() {
            for (int i = 0; i < 2; i++) {
                child[i] = NULL;
                dp[i] = -INF;
            }
        }
    };

    Node *head;

    Trie() {
        head = new Node();
    }

    void insert(int val, int idx, int res) {
        Node *cur = head;
        for (int i = K; i >= 0; i--) {
            bool v = val & (1 << i);
            if (cur->child[v] == NULL) {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
            bool bit = idx & (1 << i);
            cur->dp[bit] = max(cur->dp[bit], res);
        }
    }

    int getMax(int val, int idx) {
        int res = 1;
        Node *cur = head;
        for (int i = K; i >= 0 && cur != NULL; i--) {
            bool v = val & (1 << i);
            bool w = (v ^ 1);
            if (cur->child[w] != NULL) {
                bool bit = idx & (1 << i);
                if (!v) {
                    bit = !(bit);
                }
                res = max(res, 1 + cur->child[w]->dp[bit]);
            }
            cur = cur->child[v];
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Trie trie;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = (a[i] ^ i);
        int cur = trie.getMax(val, i);
        trie.insert(val, i, cur);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}