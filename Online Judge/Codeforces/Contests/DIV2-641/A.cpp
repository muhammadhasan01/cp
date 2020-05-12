#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        if (n % 2 == 0) {
            cout << n + 2 * k << '\n';
            continue;
        }
        long long val = -1;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                val = i;
                break;
            }
        }
        if (val == -1) val = n;
        n += val;
        n += 2 * (k - 1);
        cout << n << '\n';
    }

    return 0;
}