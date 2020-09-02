#include<bits/stdc++.h>

using namespace std;

int n, k;

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
            bool b = val & (1 << i);
            ++cur -> cnt;
            if (cur -> child[b] == NULL) {
                cur -> child[b] = new Node();
            }
            cur = cur -> child[b];
        }
        ++cur -> cnt;
    }
    int get(int val) {
        Node* cur = head;
        long long ret = 0;
        bool flag = true;
        for (int i = 30; i >= 0; i--) {
            int bit = (1 << i);
            bool b = val & bit;
            bool c = k & bit;
            if (c) {
                if (cur -> child[b ^ 1] != NULL) {
                    cur = cur -> child[b ^ 1];
                } else {
                    flag = false;
                    break;
                }
            } else {
                if (cur -> child[b ^ 1] != NULL) {
                    ret += (1LL) * (cur -> child[b ^ 1] -> cnt);
                }
                if (cur -> child[b] != NULL) {
                    cur = cur -> child[b];
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) ret += (cur -> cnt);
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    Trie trie;
    int prexor = 0;
    trie.insert(prexor);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        prexor ^= x;
        ans += trie.get(prexor);
        trie.insert(prexor);
    }
    cout << ans << '\n';

    return 0;
}
