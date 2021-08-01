#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> adj[N];
bool is_leave[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        int len = adj[i].size();
        if (len == 1) {
            is_leave[i] = true;
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int len = adj[i].size();
        if (len != 2) {
            continue;
        }
        bool ok = false;
        for (int j : adj[i]) {
            if (is_leave[j]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}