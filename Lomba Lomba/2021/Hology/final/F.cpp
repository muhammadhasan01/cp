#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        ans += p[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
    }
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < n; i++) {
        ans -= p[i].second * i;
    }
    cout << ans << '\n';

    return 0;
}