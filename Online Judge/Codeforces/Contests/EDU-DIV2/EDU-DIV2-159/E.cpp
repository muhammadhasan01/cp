#include <bits/stdc++.h>

using namespace std;

struct Trie {
    struct Node {
        Node *child[26];
        int cnt;
        int sum;
        int leaf;
        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            cnt = 0;
            sum = 0;
            leaf = 0;
        }
    };
 
    Node *head;
 
    Trie() {
        head = new Node();
    }
    
    void insert(string& str) {
        Node *cur = head;
        int len = (int) str.size();
        for (char cc : str) {
            int num = cc - 'a';
            if (cur->child[num] == NULL) {
                cur->child[num] = new Node();
            }
            cur = cur->child[num];
            cur->sum += len--;
            cur->cnt += 1;
        }
        cur->leaf++;
    }

    long long get(string& str) {
        Node *cur = head;
        int len = (int) str.size();
        long long ret = 0;
        for (char cc : str) {
            int num = cc - 'a';
            for (int i = 0; i < 26; i++) {
                if (i == num || cur->child[i] == NULL) {
                    continue;
                }
                ret += 1LL * len * cur->child[i]->cnt;
                ret += cur->child[i]->sum;
            }
            cur = cur->child[num];
            if (cur == NULL) {
                break;
            }
            --len;
            ret += cur->leaf * len;
        }
        for (int i = 0; i < 26; i++) {
            if (cur == NULL || cur->child[i] == NULL) {
                continue;
            }
            ret += cur->child[i]->sum;
        }
        return ret;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.insert(s[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        ans += trie.get(s[i]);
    }
    cout << ans << '\n';
    
    return 0;
}