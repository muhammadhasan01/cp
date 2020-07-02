#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long a, b;

long long F(long long x) {
    return x * (x + 1) / 2;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    long long ans = INF;
    for (long long i = 0; i <= 1000; i++) {
        ans = min(ans, F(abs(a - i)) + F(abs(b - i)));
    }
    cout << ans << '\n';

    return 0;
}