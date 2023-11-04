#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void solve() {
    string s;
    vector<int> cnt(K);
    for (int i = 0; i < 2; i++) {
        cin >> s;
        for (char cc : s) {
            int num = cc - 'a';
            cnt[num]++;
        }
    }
    int mx = 0;
    int two = 0;
    for (int i = 0; i < K; i++) {
        mx = max(mx, cnt[i]);
        if (cnt[i] == 2) {
            two++;
        }
    }
    if (mx == 4) {
        cout << 0 << '\n';
        return;
    }
    if (mx == 3) {
        cout << 1 << '\n';
        return;
    }
    if (mx == 1) {
        cout << 3 << '\n';
        return;
    }
    if (two == 2) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
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