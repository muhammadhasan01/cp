#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int len = n;
    for (int i = 2; i <= n; i += 2) {
        ans[i] = a[len--];
    }
    for (int i = 1; i <= n; i += 2) {
        ans[i] = a[len--];
    }
    bool ok = true;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            if (ans[i - 1] >= ans[i]) {
                ok = false;
                break;
            }
        } else {
            if (ans[i - 1] <= ans[i]) {
                ok = false;
                break;
            }
        }
    }
    if (!ok) {
        cout << -1 << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " \n"[i == n];
        }
    }

    return 0;
}