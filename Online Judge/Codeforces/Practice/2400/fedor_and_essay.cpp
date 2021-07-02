#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;
    auto norm = [&](string& s) -> void {
        for (char& cc : s) {
            cc = tolower(cc);
        }
    };
    vector<string> a(m);
    for (string& x : a) {
        cin >> x;
        norm(x);
    }
    auto count_r = [&](string& s) -> int {
        int ret = 0;
        for (char& cc : s) {
            if (cc == 'r' || cc == 'R') {
                ++ret;
            }
        }
        return ret;
    };
    int n;
    cin >> n;
    map<string, vector<string>> adj;
    set<pair<pair<int, int>, string>> st;
    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;
        norm(u); norm(v);
        adj[v].emplace_back(u);
        st.insert({{count_r(u), (int) u.size()}, u});
        st.insert({{count_r(v), (int) v.size()}, v});
    }
    map<string, pair<int, int>> dp;
    vector<string> q;
    for (auto& [p, s] : st) {
        if (dp.count(s) > 0) {
            continue;
        }
        dp[s] = p;
        q.clear();
        q.emplace_back(s);
        for (int i = 0; i < (int) q.size(); i++) {
            string& u = q[i];
            if (adj.count(u) == 0) {
                continue;
            }
            for (auto& v : adj[u]) {
                if (dp.count(v) == 0) {
                    dp[v] = p;
                    q.emplace_back(v);
                }
            }
        }
    }
    long long min_r = 0, min_length = 0;
    for (string& x : a) {
        int u = count_r(x);
        int v = (int) x.size();
        if (dp.count(x) > 0) {
            tie(u, v) = dp[x];
        }
        min_r += u;
        min_length += v;
    }
    cout << min_r << ' ' << min_length << '\n';

    return 0;
}