#include <bits/stdc++.h>

using namespace std;

const int N = 30;
long long n, p;
long long pre[N + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= 50; i++) {
        int k = n - i * p;
        if (k <= 0) continue;
        int cnt = __builtin_popcount(k);
        if (cnt > i || i > k) continue;
        cout << i << '\n';
        return 0;
    }
    cout << -1 << '\n';

    return 0;
}
