#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int tc;
int n;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        int l = n + 1, r = 0, k = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < b[i]) {
                l = min(l, i);
                r = max(r, i);
                k = b[i] - a[i];
            }
        }
        for (int i = l; i <= r; i++) {
            a[i] += k;
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}
