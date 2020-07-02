#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
int a[N], c[N];
int cnt[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    int ans = 0;
    for (int i = k; i >= 1; i--) {
        cnt[i] += cnt[i + 1];
        ans = max(ans, (cnt[i] + c[i] - 1) / c[i]);
    }
    vector<vector<int>> res(ans);
    for (int i = 1; i <= n; i++) {
        res[(i - 1) % ans].push_back(a[i]);
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << res[i].size() << ' ';
        for (auto& e : res[i]) cout << e << " ";
        cout << '\n';
    }

    return 0;
}