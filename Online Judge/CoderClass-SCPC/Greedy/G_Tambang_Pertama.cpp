#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pll;

const int N = 1e5 + 5;

int n;
long long w;
pair<long long, long long> p[N];

bool comp(const pll& x, const pll& y) {
    return x.first * y.second < y.first * x.second;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first;
    for (int i = 1; i <= n; i++)
        cin >> p[i].second;
    sort(p + 1, p + 1 + n, comp);
    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        long long res = min(w, p[i].first);
        ans += ((long double) (p[i].second)) * (((long double) res) / (long double) p[i].first);
        w -= res;
    }
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}