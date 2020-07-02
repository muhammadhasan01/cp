#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
string s;
int x, n, a[N];
unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> s;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }
    long long g = 0;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = i; j <= n; j++) {
            res += a[j];
            m[res]++;
            if (res != 0) g++;
        }
    }

    long long ans = 0;

    if (x == 0) {
        ans = 2 * g * (1LL) * m[0] + (1LL) * m[0] * m[0];
        cout << ans << '\n';
        return 0;
    }

    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            long long cur = (1LL) * m[i] * m[x / i];
            if (i * i != x) cur *= 2;
            ans += cur;
        }
    }
    cout << ans << '\n';

    return 0;
}
