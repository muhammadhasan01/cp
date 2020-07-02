#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 2e6 + 5;

int tc;
int n;
long long fib[N];

void solve() {
    cin >> n;
    cout << fib[n] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fib[3] = 4;
    fib[4] = 4;
    for (int i = 5; i < N; i++) {
        fib[i] = (fib[i - 1] + 2LL * fib[i - 2]) % M;
        if (i % 3 == 0) fib[i] = (fib[i] + 4) % M;
    }
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}