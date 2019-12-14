#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;
int n;
vector<int> g[N], rg[N];
bool prt[N];
int dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prt[i] = (x & 1);
        if (x + i <= n) {
            g[i].push_back(x + i);
            rg[x + i].push_back(i);
        }
        if (i - x >= 1) {
            g[i].push_back(i - x);
            rg[i - x].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = inf;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        for (auto e : g[i]) {
            if (prt[i] != prt[e]) {
                dp[i] = 1;
            }
        }
        if (dp[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : rg[u]) {
            if (prt[u] == prt[v]) {
                if (dp[v] > dp[u] + 1) {
                    dp[v] = dp[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] == inf) dp[i] = -1;
        cout << dp[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
