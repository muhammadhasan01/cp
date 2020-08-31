#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long INF = 1e18;

int n;
int r[3], d;
int a[N];
long long pre[N], suf[N];
long long haha[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> r[i];
    }
    cin >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = (1LL) * a[i] * r[0] + (1LL) * r[2] + pre[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        long long cur = (1LL) * a[i] * r[0] + (1LL) * r[2];
        long long val = min((1LL) * r[1], (1LL) * r[0] * (a[i] + 1)) + r[0];
        if (i == n) {
            cur = min(cur, 2LL * d + val);
            suf[i] = cur + suf[i + 1];
            cur = min(cur, d + val);
            haha[i] = cur + haha[i + 1];
        } else {
            cur = min(cur, val);
            suf[i] = cur + suf[i + 1];
            haha[i] = cur + haha[i + 1];
        }
    }
    long long ans = INF;
    for (int i = 1; i <= n + 1; i++) {
        long long cur = pre[i - 1];
        long long L = (1LL) * (i - 1) * d;
        long long R = (2LL) * (n - i) * d;
        if (i == n + 1) {
            ans = min(ans, cur + L);
        } else if (i < n) {
            int len = (n - i + 1);  
            if (len & 1)
                cur += suf[i];
            else
                cur += haha[i];
            ans = min(ans, cur + L + R);
        }
    }
    cout << ans << '\n';

    return 0;
}