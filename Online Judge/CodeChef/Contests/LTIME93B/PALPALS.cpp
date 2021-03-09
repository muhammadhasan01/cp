#include <bits/stdc++.h>

using namespace std;

void solve() {
    string str;
    cin >> str;
    vector<int> cnt(30);
    for (char cc : str) {
        cnt[(int) (cc - 'a')]++;
    }
    int odd = 0, even = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            odd++;
            cnt[i]--;
        }
        even += cnt[i] / 2;
    }
    cout << (even >= odd ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}