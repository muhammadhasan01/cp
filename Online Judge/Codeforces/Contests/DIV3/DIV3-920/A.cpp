#include <bits/stdc++.h>

using namespace std;

const int K = 4;

void solve() {
    vector<pair<int, int>> P(K);
    for (int i = 0; i < K; i++) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(), P.end(), [&](auto& x, auto& y) {
        return x.first + x.second < y.first + y.second;
    });
    cout << abs(P[0].first - P[K - 1].first) * abs(P[0].second - P[K - 1].second) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}