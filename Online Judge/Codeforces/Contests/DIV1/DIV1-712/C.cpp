#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
pair<int, int> p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1, p + 1 + n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += p[i].second;
    }
    int maks = 0;
    for (int i = 1; i < n; i++) {
        maks = max(maks, p[i].first + p[i].second);
        if (p[i + 1].first > maks) {
            ans += p[i + 1].first - maks;
        }
    }
    cout << ans << '\n';

    return 0;
}