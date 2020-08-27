#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long INF = 1e18;

int n;
int a[N];
long long pre[N], suf[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + (1LL) * (i - 1) * (a[i] - a[i - 1]);
    }
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = suf[i + 1] + (1LL) * (n - i) * (a[i + 1] - a[i]);
    }
    long long ans = INF;
    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (pre[i] + suf[i] < ans) {
            ans = pre[i] + suf[i];
            res = a[i];
        }
    }
    cout << res << '\n';

    return 0;
}