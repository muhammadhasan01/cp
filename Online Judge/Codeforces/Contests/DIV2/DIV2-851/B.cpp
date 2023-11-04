#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << ' ' << n / 2 << '\n';
        return;
    }

    auto getSumDigits = [&](int x) -> int {
        int ret = 0;
        while (x > 0) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    };

    int x = n / 2;
    int y = x + 1;
    int sumX = getSumDigits(x);
    int sumY = getSumDigits(y);
    if (abs(sumX - sumY) <= 1) {
        cout << x << ' ' << y << '\n';
        return;
    }

    string sx = to_string(x);
    string sy = to_string(y);
    int p = sx.length();
    int q = sy.length();
    if (q > p) {
        assert(p + 1 == q);
        if (p % 2 == 0) {
            for (int i = 1; i < p; i += 2) {
                swap(sx[i], sy[i + 1]);
            }
        } else {
            for (int i = 1; i < p - 1; i += 2) {
                swap(sx[i], sy[i + 1]);
            }
            sx[p - 1] = '5';
            sy[q - 1] = '4';
        }
    } else {
        assert(p == q);
        int over = 0;
        for (int i = 0; i < p; i++) {
            if (sx[i] == sy[i]) {
                continue;
            }
            char mid = (sx[i] + sy[i]) / 2;
            if (over) {
                sx[i] = mid + 1;
                sy[i] = mid;
            } else {
                sx[i] = mid;
                sy[i] = mid + 1;
            }
            over ^= 1;
        }
    }
    cout << sx << ' ' << sy << '\n';
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