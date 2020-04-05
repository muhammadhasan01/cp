#include <bits/stdc++.h>

using namespace std;

const int K = 1e5 + 5;

long long n, k;
long long ans[K];

void dismiss() {
    cout << "NO" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long mini = k * (k + 1) / 2;
    long long m = n;
    if (n < mini) dismiss();
    n -= mini;
    iota(ans + 1, ans + 1 + k, 1);
    ans[0] = 1e9;
    long long pre = 0;
    long long sum = 0;
    for (long long i = 1; i <= k; i++) {
        ans[i] += pre;
        long long l = 0;
        long long r = 2 * ans[i - 1]  - ans[i];
        long long at = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (mid * (k - i + 1) <= n) {
                at = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        n -= at * (k - i + 1);
        ans[i] += at;
        pre += at;
        sum += ans[i];
    }
    if (sum != m) dismiss();
    cout << "YES" << '\n';
    for (int i = 1; i <= k; i++) {
        cout << ans[i] << (i == k ? '\n' : ' ');
    }

    return 0;
}