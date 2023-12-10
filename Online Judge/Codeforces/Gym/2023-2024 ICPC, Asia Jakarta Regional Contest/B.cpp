#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    auto getInvariant = [&](string a) {
        int cnt = 0;
        for (int i = 0, l = 0; i < n; i++) {
            if (a[i] == '0') {
                continue;
            }
            if (i + 1 < n) {
                if (i == l) {
                    cnt += 1;
                    l++;
                } else if (i == l + 1) {
                    a[i + 1] = (a[i + 1] == '0' ? '1' : '0');
                    cnt += 2;
                    l += 2;
                } else {
                    a[i + 1] = (a[i + 1] == '0' ? '1' : '0');
                    cnt += 2;
                    l += 2;
                }
            } else {
                if (i == l) {
                    ++cnt;
                } else if (i == l + 1) {
                    cnt += 2;
                } else {
                    cnt += 2;
                }
            }
        }
        return (cnt + 1) / 2;
    };

    cout << (getInvariant(s) == getInvariant(t) ? "YES" : "NO") << '\n';
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