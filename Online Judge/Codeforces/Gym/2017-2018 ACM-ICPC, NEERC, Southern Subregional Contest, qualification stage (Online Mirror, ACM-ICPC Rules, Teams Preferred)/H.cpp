#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n;
int a[N];
pair<int, long long> pre[N], suf[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i].first = max(pre[i - 1].first + 1, a[i]);
        pre[i].second = (1LL) * (pre[i].first - a[i]) + pre[i - 1].second;
    }
    for (int i = n; i >= 1; i--) {
        suf[i].first = max(suf[i + 1].first + 1, a[i]);
        suf[i].second = (1LL) * (suf[i].first - a[i]) + suf[i + 1].second;
    }
    long long ans = INF;
    for (int i = 1; i <= n; i++) {
        int cur = max(a[i], max(pre[i - 1].first, suf[i + 1].first) + 1);
        long long res = (1LL) * (cur - a[i]) + pre[i - 1].second + suf[i + 1].second;
        ans = min(ans, res);
    }
    cout << ans << '\n';

    return 0;
}