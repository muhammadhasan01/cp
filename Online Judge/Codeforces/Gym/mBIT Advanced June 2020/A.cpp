#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, q;
int a[N];
long long pre[N], suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        long long x = pre[r - 1] - pre[l - 1];
        long long y = suf[r] + pre[l - 1];
        cout << min(x, y) << '\n';
    }

    return 0;
}