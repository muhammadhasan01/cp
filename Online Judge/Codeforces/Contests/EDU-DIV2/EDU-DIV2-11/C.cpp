#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, k;
char a[N];
int pre[N];

bool can(int x) {
    for (int i = 1; i <= n - x + 1; i++) {
        int res = pre[i + x - 1] - pre[i - 1];
        if (res <= k) return true;
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + (a[i] == '0');
    }
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    if (ans > 0) {
        for (int i = 1; i <= n - ans + 1; i++) {
            int res = pre[i + ans - 1] - pre[i - 1];
            if (res <= k) {
                for (int j = i; j <= i + ans - 1; j++) {
                    a[j] = '1';
                }
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}