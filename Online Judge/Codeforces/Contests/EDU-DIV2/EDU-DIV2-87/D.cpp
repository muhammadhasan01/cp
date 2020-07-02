#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, q;
int a[N];
int bit[N];

void add(int x, int val) {
    for ( ; x <= n; x += x & -x) {
        bit[x] += val;
    }
}

int get(int x) {
    if (x == 0) return 0;
    int ret = 0;
    for ( ; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(x, 1);
    }
    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        if (k > 0) {
            add(k, 1);
        } else {
            int l = 1, r = n, pos = 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(mid) >= -k) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            add(pos, -1);
        }
    }
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(mid) >= 1) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}