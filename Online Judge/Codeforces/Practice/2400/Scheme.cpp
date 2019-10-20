#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, f[N];
int deg[N], last[N], chain[N];
bitset<N> used;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        deg[f[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i]) continue;
        int x = i;
        used[x] = 1;

        while (chain[x] == 0) {
            chain[x] = i;
            x = f[x];
        }
        last[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        if (chain[i]) continue;
        int x = f[i];
        used[i] = 1, chain[x] = chain[i] = i;
        while (x != i) {
            chain[x] = i;
            x = f[x];
        }
        last[i] = i;
    }
    vector<pair<int,int>> ans;
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            ans.push_back({last[i], i});
        }
    }

    if ((int) ans.size() == 1 && ans[0].first == ans[0].second) {
        puts("0");
        return 0;
    }

    int k = ans.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << ans[i].first << " " << ans[(i + 1) % k].second << '\n';
    }

    return 0;
}
