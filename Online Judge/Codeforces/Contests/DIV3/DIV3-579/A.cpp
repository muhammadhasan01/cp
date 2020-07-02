#include<bits/stdc++.h>
using namespace std;

int q;
int n;
int a[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i + n] = a[i];
        }

        if (n == 1) {
            puts("YES");
            continue;
        }

        bool ok = false;
        for (int i = 1; i <= n; i++) {
            bool tr = true;
            for (int j = i, cnt = 1; j <= i + n - 1; j++, cnt++) {
                tr &= a[j] == cnt;
            }
            ok |= tr;
        }

        for (int i = 2 * n; i >= n + 1; i--) {
            bool tr = true;
            for (int j = i, cnt = 1; j >= i - n + 1; j--, cnt++) {
                tr &= a[j] == cnt;
            }
            ok |= tr;
        }
        puts(ok ? "YES" : "NO");
    }

    return 0;
}
