#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 2e5 + 5;

int n;
int a[N];
int par[N];
vector<int> members[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

bool merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return false;
    par[pv] = pu;
    return true;
}

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

    void add(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            ++cur -> cnt;
            if (cur -> child[v] == NULL) {
                cur -> child[v] = new Node();
            }
            cur = cur -> child[v];
        }
        ++cur -> cnt;
    }

    void erase(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            --cur -> cnt;
            cur = cur -> child[v];
        }
        --cur -> cnt;
    }

    int getMinXOR(int val) {
        Node *cur = head;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            if (cur -> child[v] != NULL && cur -> child[v] -> cnt != 0) {
                cur = cur -> child[v];
            } else {
                cur = cur -> child[v ^ 1];
                res += (1 << i);
            }
        }
        return res;
    }
} trie;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    unordered_map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        trie.add(a[i]);
        pos[a[i]] = i;
        par[i] = i;
    }
    int comp = n;
    long long ans = 0;
    while (comp > 1) {
        for (int i = 1; i <= n; i++) {
            members[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            members[fpar(i)].emplace_back(i);
        }
        vector<tuple<int, int, int>> edges;
        for (int i = 1; i <= n; i++) {
            if (members[i].empty()) {
                continue;
            }
            for (int id : members[i]) {
                trie.erase(a[id]);
            }
            int mini = INF, val = -1;
            for (int id : members[i]) {
                int cur = trie.getMinXOR(a[id]);
                if (cur < mini) {
                    mini = cur;
                    val = (a[id] ^ cur);
                }
            }
            int j = fpar(pos[val]);
            int u = i, v = j;
            if (u > v) swap(u, v);
            edges.emplace_back(u, v, mini);
            for (int id : members[i]) {
                trie.add(a[id]);
            }
        }
        for (auto& [u, v, res] : edges) {
            if (!merge(u, v)) continue;
            ans += res;
            comp--;
        }
    }
    cout << ans << '\n';

    return 0;
}