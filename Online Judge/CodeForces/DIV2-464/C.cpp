#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], s, f;
int b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    cin >> s >> f;
    int dif = f - s;
    int cur = 0;
    for (int i = 1; i <= dif; i++) {
        cur += a[i];
    }
    b[1] = cur;
    int ans = cur, pos = 1;
    for (int i = 2; i <= n; i++) {
        cur -= a[i - 1];
        cur += a[i + dif - 1];
        if (cur > ans) {
            ans = cur;
            pos = i;
        }
        b[i] = cur;
    }
    int res = n + 1;
    for (int i = 1; i <= n; i++) {
        if (b[i] == ans) {
            int cres = (s - i + 1);
            if (cres <= 0) cres += n;
            res = min(res, cres);
        }
    }
    
    cout << res << '\n';

    return 0;
}
