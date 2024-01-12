#include <bits/stdc++.h>

using namespace std;

const int A = 26;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(A);
    int ans = 0;
    int add = 0;
    for (int i = 0; i < n; i++) {
        int num = s[i] - 'a';
        if (++cnt[num] == 1) {
            add++;
        }
        ans += add;
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