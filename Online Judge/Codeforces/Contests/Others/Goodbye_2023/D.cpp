#include <bits/stdc++.h>

using namespace std;

map<int, vector<string>> memo;

vector<string> DP(int n) {
    if (n == 1) {
        return {"1"};
    }
    if (n == 3) {
        return {"169", "196", "961"};
    }
    if (memo.count(n)) {
        return memo[n];
    }
    vector<string> res = DP(n - 2);
    vector<string> ret;
    for (string s : res) {
        ret.emplace_back(s + "00");
    }
    int len = n / 2 - 1;
    ret.emplace_back("1" + string(len, '0') + "6" + string(len, '0') + "9");
    ret.emplace_back("9" + string(len, '0') + "6" + string(len, '0') + "1");
    return memo[n] = ret;
}

void solve() {
    int n;
    cin >> n;
    vector<string> ans = DP(n);
    for (string x : ans) {
        cout << x << '\n';
    }
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