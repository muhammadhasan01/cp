#include <bits/stdc++.h>

using namespace std;

int tc;
string s;

void solve() {
    cin >> s;
    int n = s.length();
    vector<int> v;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ++res;
        } else {
            v.emplace_back(res);
            res = 0;
        }
    }
    if (res > 0) v.emplace_back(res);
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < (int) v.size(); i += 2)
        ans += v[i];
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}