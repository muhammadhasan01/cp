#include <bits/stdc++.h>

using namespace std;

int q;
int a[105];
bool vis[105];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vis[i] = 0;
        }
        sort(a + 1, a + 1 + n);
        bool ok = false;
        for (int i = 1; i <= n - 1; i++) {
            if (a[i] == a[i + 1] - 1) {
                ok = true;
            }
        }
        cout << (ok ? 2 : 1) << '\n';
    }

    return 0;
}
