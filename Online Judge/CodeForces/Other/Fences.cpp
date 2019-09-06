#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 5;
int n, a[N];

ll solve(int l, int r) {
    cerr << l << " " << r << '\n';
    if (l == r) return 1;
    ll ret = 0;
    int mini = 1e9;
    for (int i = l; i <= r; i++) mini = min(mini, a[i]);

    if (mini >= r - l + 1) return (r - l + 1);

    int cnt = 0;
    for (int i = l; i <= r; i++) {
        a[i] -= mini;
        if (a[i] == 0) cnt++;
    }
    ret += (1LL) * mini;
    if (cnt == r - l + 1) return ret;
    int left = l, right = r;
    for (int i = l; i <= r; i++) {
        if (a[i] > 0) continue;
        if (i == l) {
            left = i + 1;
        } else {
            right = i - 1;
            ret += solve(left, right);
            left = i + 1;
        }
    }
    ret += solve(left, r);
    return min(ret, (1LL) * (r - l + 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << solve(1, n) << '\n';

    return 0;
}
