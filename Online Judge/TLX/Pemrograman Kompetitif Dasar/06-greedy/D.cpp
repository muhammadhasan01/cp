#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long d;
    cin >> n >> d;
    vector<pair<long long, long long>> p(n);
    for (auto& [h, b] : p) {
        cin >> h >> b;
    }
    sort(p.begin(), p.end());
    long long ans = 0;
    for (auto& [h, b] : p) {
        long long take = min(b, d / h);
        ans += take;
        d -= take * h;
    }
    cout << ans << '\n';
    
    return 0;
}