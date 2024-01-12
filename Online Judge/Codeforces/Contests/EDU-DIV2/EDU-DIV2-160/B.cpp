#include <bits/stdc++.h>

using namespace std;

const int B = 2;

void solve() {
    string s;
    cin >> s;
    int n = (int) s.length();
    vector<int> cnt(B);
    for (char cc : s) {
        cnt[(int) (cc - '0')]++;
    }
    int ans = n;
    vector<int> freq(B);
    for (int i = 0; i < n; i++) {
        int num = (int) (s[i] - '0');
        num ^= 1;
        freq[num]++;
        if (freq[0] <= cnt[0] && freq[1] <= cnt[1]) {
            ans = n - i - 1;
        }
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