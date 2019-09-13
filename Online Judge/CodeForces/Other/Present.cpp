#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = (int) 1e9 + (int) 1e5 + 5;
int n, m, w;
int a[N];

bool check(int x) {
    vector<int> st(n + 1, 0);
    int cur = 0, move = 0;
    for (int i = 1; i <= n; i++) {
        cur -= (i - w >= 1 ? st[i - w] : 0);
        if (a[i] + cur < x) {
            st[i] = x - a[i] - cur;
            cur += st[i];
            move += st[i];
        }
        if (move > m) return false;
    }
    return (move <= m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = M, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
