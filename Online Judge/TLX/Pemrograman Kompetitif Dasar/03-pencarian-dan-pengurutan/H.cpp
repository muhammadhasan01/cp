#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
    }
    sort(p.begin(), p.end(), [&](auto& l, auto& r) {
        return l.first * r.second < l.second * r.first;
    });
    long double res = 0;
    for (int i = 0; i < n; i++) {
        int need = min(x, p[i].first);
        x -= need;
        res += (long double) need * p[i].second / p[i].first;
    }
    cout << fixed << setprecision(9) << res << '\n';
    
    return 0;
}