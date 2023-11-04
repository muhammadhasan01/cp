#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> odd, even;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (i % 2 == 1) {
            odd.emplace_back(x);
        } else {
            even.emplace_back(x);
        }
    }

    auto get = [&](vector<long long>& v) -> long long {
        if (v.empty()) {
            return -INF;
        }
        sort(v.rbegin(), v.rend());
        if (v[0] <= 0) {
            return v[0];
        }
        long long ret = 0;
        for (long long x : v) {
            if (x <= 0) {
                break;
            }
            ret += x;
        }
        return ret;
    };

    cout << max(get(odd), get(even)) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}