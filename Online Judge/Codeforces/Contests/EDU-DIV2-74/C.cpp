#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int q;
long long h;
int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> h >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        n++;
        a[n] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i + 2 <= n && a[i + 2] - a[i + 1] == -1) {
                i++;
            } else if (i < n - 1) {
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
