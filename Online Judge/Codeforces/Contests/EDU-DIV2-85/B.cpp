#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int len;
long long x;
long long a[N], b[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        len = 0;
        long long sum = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > x) {
                ans++;
                sum += a[i];
            } else {
                b[++len] = a[i];
            }
        }
        sort(b + 1, b + 1 + len, greater<long long>());
        for (int i = 1; i <= len; i++) {
            sum += b[i];
            if (sum >= x * (ans + 1)) {
                ++ans;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}