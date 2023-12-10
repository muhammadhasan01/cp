#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int dp[N];

void solve() {
    int n;
    cin >> n;
    int XOR = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        XOR ^= dp[x];
    }
    cout << (XOR > 0 ? 1 : 2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> divisors(N);
    for (int i = 2; i < N; i++) {
        if (i % 2 == 1) {
            for (int j = i; j < N; j += i) {
                divisors[j].emplace_back(i);
            }
        }
        int len = (int) divisors[i].size();
        vector<int> vals(len);
        for (int j = 0; j < len; j++) {
            vals[j] = dp[divisors[i][j]];
        }
        vals.emplace_back(0);
        sort(vals.begin(), vals.end());
        while (binary_search(vals.begin(), vals.end(), dp[i])) {
            dp[i]++;
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}