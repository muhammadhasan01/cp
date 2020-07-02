#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
const long long INF = 1e16;

int a, b, c, d;
long long pre[N], prez[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d;
    for (int i = b; i < N; i++) {
        pre[i] = pre[i - 1];
        if (i <= c) pre[i]++;
    }
    for (int i = b; i < N; i++) {
        prez[i] = min(INF, pre[i] + prez[i - 1]);
    }
    long long ans = 0;
    for (int i = c; i <= d; i++) {
        long long res = (prez[i + b - 1] - prez[i + a - 2]) - (prez[i - a] - prez[max(0, i - b - 1)]);
        ans += res;
    }
    cout << ans << '\n';

    return 0;
}