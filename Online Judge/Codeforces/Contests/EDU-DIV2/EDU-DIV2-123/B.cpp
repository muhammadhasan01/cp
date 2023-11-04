#include <bits/stdc++.h>

using namespace std;

map<int, vector<vector<int>>> memo;

vector<vector<int>> solve(int n) {
    if (memo.count(n)) {
        return memo[n];
    }
    if (n == 3) {
        return memo[3] = {{3, 2, 1}, {3, 1, 2}, {2, 3, 1}};
    }
    vector<vector<int>> res = solve(n - 1);
    for (auto& v : res) {
        v.insert(v.begin(), n);
    }
    vector<int> fst = res[0];
    swap(fst[0], fst[1]);
    res.insert(res.begin(), fst);
    return memo[n] = res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans = solve(n);
    for (auto& res : ans) {
        for (int i = 0; i < n; i++) {
            cout << res[i] << " \n"[i == n - 1];
        }
    }
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