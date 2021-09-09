#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> divisors[N];

void solve() {
    int n;
    cin >> n;
    vector<int> u(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> nums(n + 1);
    for (int i = 0; i < n; i++) {
        nums[u[i]].emplace_back(s[i]);
    }
    vector<long long> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if (nums[i].empty()) {
            continue;
        }
        int len = nums[i].size();
        sort(nums[i].rbegin(), nums[i].rend());
        vector<long long> pre(len + 1);
        for (int j = 1; j <= len; j++) {
            pre[j] = pre[j - 1] + nums[i][j - 1];
        }
        for (int j = 1; j <= len; j++) {
            for (int x : divisors[j]) {
                ans[x] += pre[j] - pre[j - x];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}