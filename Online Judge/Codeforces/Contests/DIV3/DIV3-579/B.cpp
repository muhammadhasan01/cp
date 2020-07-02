#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 100 + 5;
int q;
int n, a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        n = 4 * n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        bool ok = true;
        for (int i = 1, j = 1; i <= n; i += 2, j++) {
            b[j] = a[i];
            ok &= (a[i] == a[i + 1]);
        }
        int res = b[1] * b[n/2];
        for (int i = 1; i <= n/2; i++) {
            ok &= (res == b[i] * b[n/2 - i + 1]);
        }
        puts(ok ? "YES" : "NO");
    }

    return 0;
}
