#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll INF = 4e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll C;
    cin >> n >> C;
    array<ll,24> minSlices;
    minSlices.fill(INF);
    for (int i = 0; i < n; i++) {
        int t;
        ll p;
        cin >> t >> p;
        minSlices[t] = min(minSlices[t], p);
    }
    vector<ll> costs;
    costs.reserve(24);
    for (int h = 0; h < 24; h++) {
        if (minSlices[h] != INF) {
            costs.push_back(minSlices[h]);
        }
    }
    sort(costs.begin(), costs.end());
    ll used = 0;
    int attended = 0;
    for (ll cost : costs) {
        if (used + cost > C) break;
        used += cost;
        attended++;
    }
    cout << attended << '\n';
    
    return 0;
}