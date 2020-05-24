#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int K = 20;
const int N = (1 << K);
const int NMax = 1e6;

int n;
long long d[N];
long long pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        d[x]++;
    }
    pre[0] = 1;
    for (int i = 1; i < N; i++) {
        pre[i] = (pre[i - 1] << 1) % M;
    }
    for (int i = 0; i < K; i++) {
        for (int mask = 0; mask < N; mask++) {
            if (!(mask & (1 << i))) {
                d[mask] += d[mask | (1 << i)];
            }
        }
    }
    long long total = (pre[n] - 1 + M) % M;
    for (int mask = 1; mask < N; mask++) {
        int bitz = __builtin_popcount(mask);
        total = (total + (bitz % 2 == 0 ? 1 : -1) * (pre[d[mask]] - 1 + M)) % M;
    }
    cout << (total % M + M) % M << '\n';

    return 0;
}