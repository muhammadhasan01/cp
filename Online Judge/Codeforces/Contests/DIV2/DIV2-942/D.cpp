#include <bits/stdc++.h>

using namespace std;

template<typename T>
vector<pair<T, int>> getFreq(vector<T>& v) {
    assert(is_sorted(v.begin(), v.end()));
    vector<pair<T, int>> freq;
    for (T x : v) {
        if (freq.empty() || freq.back().first != x) {
            freq.emplace_back(x, 1);
            continue;
        }
        auto [_, cnt] = freq.back();
        freq.pop_back();
        freq.emplace_back(x, cnt + 1);
    }
    return freq;
}

void solve() {
    int n, b, x;
    cin >> n >> b >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    auto getPair = [&](int k, int val) -> long long {
        long long div = val / k;
        long long rem = val % k;
        long long total = val;
        long long X = rem * (div + 1) * (total - div - 1);
        long long Y = (k - rem) * div * (total - div);
        return (X + Y) / 2;
    };
    
    sort(c.begin(), c.end());
    vector<pair<int, int>> freq = getFreq(c);
    long long ans = 0;
    for (int k = 1; k <= c[n - 1]; k++) {
        long long cur = -1LL * (k - 1) * x;
        for (auto [val, cnt] : freq) {
            cur += getPair(k, val) * cnt * b;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
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