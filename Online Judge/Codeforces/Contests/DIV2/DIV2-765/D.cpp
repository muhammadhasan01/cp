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
};

const int K = 30;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k == 0) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " \n"[i == n];
        }
        return 0;
    }
    int hb = -1;
    for (int i = K; i >= 0; i--) {
        if (k & (1 << i)) {
            hb = i;
            break;
        }
    }
    assert(hb != -1);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int cur = (a[i] >> hb);
        mp[cur].emplace_back(i);
    }
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i++) {
        idx[a[i]] = i;
    }
    vector<int> ans;
    set<int> done;
    for (auto& [val, v] : mp) {
        if (done.find(val) != done.end()) {
            continue;
        }
        int oval = val ^ 1;
        if (mp.find(oval) == mp.end()) {
            ans.emplace_back(v[0]);
            continue;
        }
        Trie trie;
        for (int& i : mp[oval]) {
            trie.insert(a[i]);
        }
        bool found = false;
        for (int& i : v) {
            int mx = trie.getMaxXOR(a[i]);
            if (mx >= k) {
                found = true;
                ans.emplace_back(i);
                ans.emplace_back(idx[(mx ^ a[i])]);
                break;
            }
        }
        if (!found) {
            ans.emplace_back(v[0]);
        }
        done.emplace(val);
        done.emplace(oval);
    }
    int len = (int) ans.size();
    if (len <= 1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << len << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < len; i++) {
        cout << ans[i] + 1 << " \n"[i == len - 1];
    }
    
    return 0;
}