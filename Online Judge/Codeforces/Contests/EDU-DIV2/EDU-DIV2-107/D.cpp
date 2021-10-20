#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << string(n, 'a') << '\n';
        return 0;
    }
    string cur = ""; 
    if (k >= 2) {
        cur += "abbaa";
    }
    auto get_char = [&](int x) -> char {
        return char(int('a') + x - 1);
    };
    if (k >= 3) {
        for (int x = 3; x <= k; x++) {
            // add xx
            cur.push_back(get_char(x));
            cur.push_back(get_char(x));
            // add x (bx, cx, ...) a
            for (int y = 2; y <= x - 1; y++) {
                cur.push_back(get_char(y));
                cur.push_back(get_char(x));
            }
            cur.push_back(get_char(1));
        }
    }
    int len = cur.size();
    if (len >= n) {
        cout << cur.substr(0, n) << '\n';
        return 0;
    }
    string ans = cur;
    int m = len;
    int idx = 1;
    while (m < n) {
        ans += cur[idx];
        idx++;
        m++;
        if (idx >= len) {
            idx = 1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}