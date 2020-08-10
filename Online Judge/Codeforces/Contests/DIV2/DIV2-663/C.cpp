#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long M = 1e9 + 7;

int n;
long long fact[N];
long long pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = pre[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = ((1LL) * i * fact[i - 1]) % M;
        pre[i] = (pre[i - 1] + pre[i - 1]) % M;
    }
    cin >> n;
    long long ans = fact[n] - pre[n - 1];
    cout << (ans % M + M) % M << '\n';

    return 0;
}