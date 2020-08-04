#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long M = 1e9 + 7;

int n;
long long x[N];
long long F[N];
long long pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0] = F[0] = 1;
    for (int i = 1; i < N; i++) {
        F[i] = (F[i - 1] << 1) % M;
        pre[i] = (F[i] + pre[i - 1]) % M;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + 1 + n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long add = (i == 1 ? 0 : (x[i] * pre[i - 2]) % M);
        long long sub = (i == n ? 0 : (x[i] * pre[n - 2 - i + 1]) % M);
        ans = (ans + (add - sub)) % M;
        ans = (ans % M + M) % M;
    }
    cout << ans << '\n';

    return 0;
}