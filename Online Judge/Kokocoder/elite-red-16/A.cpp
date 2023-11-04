#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int len = s.length();
    vector<bool> mark(len);
    for (int i = 0; i < len; i++) {
        if (mark[i]) {
            continue;
        }
        if (i + 4 < len && s.substr(i, 5) == "twone") {
            mark[i + 2] = true;
        } else if (i + 2 < len && s.substr(i, 3) == "two") {
            mark[i + 1] = true;
        } else if (i + 2 < len && s.substr(i, 3) == "one") {
            mark[i + 1] = true;
        }
    }
    vector<int> ans;
    for (int i = 0; i < len; i++) {
        if (mark[i]) {
            ans.emplace_back(i + 1);
        }
    }
    int n = ans.size();
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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