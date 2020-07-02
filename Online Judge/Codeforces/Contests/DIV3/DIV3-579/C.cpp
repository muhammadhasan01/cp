#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        res = __gcd(res, x);
    }
    long long ans = 0;
    for (long long i = 1; i * i <= res; i++) {
        if (res % i == 0) {
            if (i * i != res) {
                ans += 2;
            } else {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
