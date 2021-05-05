#include <bits/stdc++.h>

using namespace std;

long long n, k;

long long get(long long x) {
    long long ret = 0;
    while (x < k) {
        x += x;
        ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        long double res = (long double) 1.0 / (1LL << get(i));
        ans += res;
    }
    cout << fixed << setprecision(12) << ans / n << '\n';

    return 0;
}