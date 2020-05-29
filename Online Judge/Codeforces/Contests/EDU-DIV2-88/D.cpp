#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 18;

struct st {
    int val, lpref, rpref;
};

st maks(const st& a, const st& b) {
    return {max(a.val, b.val), min(a.lpref, b.lpref), max(a.rpref, b.rpref)};
}

int n;
int a[N];
int prec[(1 << K)];
int pre[N], suf[N];
st sp[(1 << K)][K];

st get(int l, int r) {
    int k = prec[r - l + 1];
    return maks(sp[l][k], sp[r - (1 << k) + 1][k]);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = a[i] + pre[i - 1];
    }
    prec[1] = 0;
    for (int i = 2; i < (1 << K); i++) {
        prec[i] = prec[i >> 1] + 1;
    }
    for (int i = 0; i <= n; i++) {
        sp[i][0] = {a[i], pre[i], pre[i]};
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i <= n; i++) {
            sp[i][j] = maks(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, lpos = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(mid, i).val <= a[i]) {
                lpos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        l = i, r = n;
        int rpos = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(i, mid).val <= a[i]) {
                rpos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int leftMax = pre[i] - get(lpos - 1, i - 1).lpref;
        int rightMax = get(i, rpos).rpref - pre[i - 1];
        int cur = leftMax + rightMax - 2 * a[i];
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}