#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int L = 0;
    for (char c : s) {
        if (c == '<') {
            L++;
        }
    }
    vector<int> ans;
    ans.reserve(n);
    ans.push_back(L + 1);
    int si = L, li = L + 2;
    for (char c : s) {
        if (c == '<') {
            ans.push_back(si--);
        } else {
            ans.push_back(li++);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
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