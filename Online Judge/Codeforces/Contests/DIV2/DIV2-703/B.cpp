#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 1e3 + 5;

int n;
int x[N], y[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    auto f = [&](int* a) -> long long {
        vector<pair<long long, int>> v;
        for (int i = 1; i <= n; i++) {
            long long dist = 0;
            for (int j = 1; j <= n; j++) {
                dist += abs(a[i] - a[j]);
            }
            v.emplace_back(dist, a[i]);
        }
        sort(v.begin(), v.end());
        int mini = INF, maxi = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].first != v[0].first) break;
            mini = min(mini, v[i].second);
            maxi = max(maxi, v[i].second);
        }
        return (maxi - mini + 1);
    };

    cout << f(x) * f(y) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}