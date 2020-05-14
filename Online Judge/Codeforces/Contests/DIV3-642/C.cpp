#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int tc;
long long n, m;

long long F(long long x) {
    return x * (x + 1) / 2;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        m = n / 2;
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += F(m) - F(i);
        }
        ans = (8LL * ans);
        cout << ans << '\n';
    }

    return 0;
}