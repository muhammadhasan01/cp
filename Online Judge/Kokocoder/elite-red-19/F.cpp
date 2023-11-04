#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;
    long long ans = 1LL * n * (n - 1) / 2;
    long long t = 1, res = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i + 1]) {
            res += t;
            t = 1;
        } else {
            t++;
        }
    }
    t = 1;
    for (int i = n; i > 1; i--) {
        if (s[i] != s[i - 1]) {
            res += t - 1;
            t = 1;
        } else {
            t++;
        }
    }
    cout << ans - res << '\n';

    return 0;
}