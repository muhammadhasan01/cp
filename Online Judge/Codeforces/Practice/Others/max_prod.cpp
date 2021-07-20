#include <bits/stdc++.h>

using namespace std;

long long prod(long long x) {
    long long ret = 1;
    while (x > 0) {
        ret = (ret * (x % 10));
        x /= 10;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;
    string s = to_string(b);
    long long best = b;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        for (char d = '0'; d <= '9'; d++) {
            string t = s;
            t[i] = d;
            for (int j = i + 1; j < len; j++) {
                t[j] = '9';
            }
            if (len == 19 && t[0] != '0') {
                continue;
            }
            long long cur = stoll(t);
            if (cur < a || cur > b) {
                continue;
            }
            if (prod(cur) > prod(best)) {
                best = cur;
            }
        }
    }
    cout << best << '\n';

    return 0;
}