#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int L = n / 2, R = n / 2;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            L--;
        } else if (s[i] == ')') {
            R--;
        } else if (s[i] == '?') {
            pos.emplace_back(i);
        }
    }
    int len = (int) pos.size();
    if (len <= 1) {
        cout << "YES" << '\n';
        return;
    }
    if (L == 0 || R == 0) {
        cout << "YES" << '\n';
        return;
    }
    swap(pos[L - 1], pos[L]);
    for (int i = 0; i < len; i++) {
        int at = pos[i];
        if (i < L) {
            s[at] = '(';
        } else {
            s[at] = ')';
        }
    }
    int cur = 0;
    for (char cc : s) {
        if (cc == '(') {
            cur++;
        } else {
            cur--;
        }
        if (cur < 0) {
            cout << "YES" << '\n';
            return;
        }
    }
    if (cur != 0) {
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
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