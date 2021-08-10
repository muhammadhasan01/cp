#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int M = 2 * N;

int n, m;
tuple<int, int, int> p[N];
set<int> in[M];
set<int> out[M];
vector<int> adj[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<int> nums;
    for (int i = 1; i <= m; i++) {
        auto& [id, l, r] = p[i];
        cin >> id >> l >> r;
        r += 1;
        nums.emplace_back(l);
        nums.emplace_back(r);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    auto norm = [&](int id) -> int {
        return lower_bound(nums.begin(), nums.end(), id) - nums.begin() + 1;
    };
    for (int i = 1; i <= m; i++) {
        auto& [id, l, r] = p[i];
        l = norm(l);
        r = norm(r);
        in[l].emplace(id);
        out[r].emplace(id);
    }
    int numsize = nums.size();
    set<int> val;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= numsize; i++) {
        for (int x : out[i]) {
            if (--cnt[x] == 0) {
                auto it = val.find(x);
                if (it != val.begin() && next(it) != val.end()) {
                    adj[*prev(it)].emplace_back(*next(it));
                }
                val.erase(x);
            }
        }
        for (int x : in[i]) {
            auto it = val.emplace(x).first;
            if (++cnt[x] > 1) {
                continue;
            }
            if (it != val.begin()) {
                adj[*prev(it)].emplace_back(*it);
            }
            if (next(it) != val.end()) {
                adj[*it].emplace_back(*next(it));
            }
        }
    }
    vector<int> dp(n + 1), par(n + 1);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                par[v] = u;
            }
        }
    }
    int pos = max_element(dp.begin() + 1, dp.end()) - dp.begin();
    vector<int> vis(n + 1);
    while (true) {
        vis[pos] = true;
        if (par[pos] == pos) {
            break;
        }
        pos = par[pos];
    }
    vector<int> ans;
    for (int u = 1; u <= n; u++) {
        if (vis[u]) {
            continue;
        }
        ans.emplace_back(u);
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }

    return 0;
}