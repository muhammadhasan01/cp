#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int o = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'o') {
            continue;
        }
        o++;
        if (i - 1 >= 0) {
            s[i - 1] = '.';
        }
        if (i + 1 < n) {
            s[i + 1] = '.';
        }
    }

    auto gen = [&]() -> string {
        string p = s;
        int cnt = o;
        for (int i = 0; i < n; i++) {
            if (p[i] == 'o') {
                continue;
            }
            if (i - 1 >= 0 && p[i - 1] == 'o') {
                p[i] = '.';
            }
            if (p[i] == '.') {
                continue;
            }
            if (cnt + 1 <= k) {
                p[i] = 'o';
                cnt++;
            } else {
                p[i] = '.';
            }
        }
        return p;
    };

    string L = gen();
    reverse(s.begin(), s.end());
    string R = gen();
    reverse(R.begin(), R.end());
    reverse(s.begin(), s.end());
    if (L == R) {
        cout << L << '\n';
    } else {
        if (L[0] == R[0]) {
            s[0] = L[0];
        }
        if (L[n - 1] == R[n - 1]) {
            s[n - 1] = L[n - 1];
        }
        cout << s << '\n';
    }
    
    return 0;
}