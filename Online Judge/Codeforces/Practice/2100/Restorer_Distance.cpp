#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n;
long long a, b, c;
long long h[N], pre[N], suf[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> c;
    long long avg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        avg += h[i];
    }
    avg /= n;
    sort(h + 1, h + 1 + n);
    bool flag = true;
    for (int i = 2; i <= n; i++) {
        if (h[i] != h[i - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = h[i] + pre[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = h[i] + suf[i + 1];
    }
    c = min(c, a + b);
    long long ans = INF;
    for (long long i = 1; i <= n; i++) {
        long long Ka = (i * h[i] - pre[i]);
        long long Kb = (suf[i + 1] - h[i] * (n - i));
        long long Kc = min(Ka, Kb);
        long long cur = a * (Ka - Kc) + b * (Kb - Kc) + c * Kc;
        ans = min(ans, cur); 
    }
    int pos = upper_bound(h + 1, h + 1 + n, avg) - h - 1;
    long long Ka = (pos * avg - pre[pos]);
    long long Kb = (suf[pos + 1] - (n - pos) * avg);
    long long Kc = min(Ka, Kb);
    ans = min(ans, a * (Ka - Kc) + b * (Kb - Kc) + c * Kc);
    avg++;
    pos = upper_bound(h + 1, h + 1 + n, avg) - h - 1;
    Ka = (pos * avg - pre[pos]);
    Kb = (suf[pos + 1] - (n - pos) * avg);
    Kc = min(Ka, Kb);
    ans = min(ans, a * (Ka - Kc) + b * (Kb - Kc) + c * Kc);
    cout << ans << '\n';

    return 0;
}