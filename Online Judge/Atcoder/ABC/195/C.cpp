#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    long long cur = 1;
    int cnt = 0;
    long long ans = 0;
    while (1) {
        cur = (cur * 10);
        if (cur > n) break;
        ++cnt;
        if (cnt % 3 == 0) {
            ans += (n - cur + 1);
        }
    }
    cout << ans << '\n';

    return 0;
}