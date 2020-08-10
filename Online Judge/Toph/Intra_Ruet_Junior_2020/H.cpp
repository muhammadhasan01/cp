#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, x;

bool check(int base) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    int len = s.size();
    long long res = 1, pr = 1;
    for (int i = 0; i < len; i++) {
        int cur = s[i] - '0';
        if (cur >= base) return false;
        res += (1LL) * cur * pr;
        pr *= base;
    }
    return (x == res);
}

void solve() {
    cin >> n >> x;
    for (int base = 2; base <= 10; base++) {
        if (check(base)) {
            cout << base << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}