#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int L = 70;

int n;
int b[N];
long long a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = __builtin_popcountll(a[i]);
    }
    long long ans = 0;
    long long odd = 0, even = 0;
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        pre ^= (b[i] & 1);
        if (pre) {
            ans += odd++;
        } else {
            ans += ++even;
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0, maks = 0;
        for (int j = i; j <= min(n, i + L); j++) {
            sum += b[j];
            maks = max(maks, b[j]);
            if (sum % 2 == 0 && sum - maks < maks) {
                ans--;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}