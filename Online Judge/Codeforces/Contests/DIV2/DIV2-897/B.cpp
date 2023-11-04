#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dif = 0, same = 0;
    for (int l = 0, r = n - 1; l < r; l++, r--) {
        if (s[l] != s[r]) {
            dif++;
        } else {
            same++;
        }
    }
    int odd = (n & 1);

    auto isGood = [&](int x) -> bool {
        if (x < dif) {
            return false;
        }
        if (x == dif) {
            return true;
        }
        int rem = x - dif;
        if (rem & 1) {
            if (!odd) {
                return false;
            }
            rem--;
        }
        return rem <= 2 * same;
    };

    for (int x = 0; x <= n; x++) {
        cout << isGood(x);
    }
    cout << '\n';
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