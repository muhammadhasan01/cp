#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n;
ll s[N], bit[N];
int ans[N];

void add(ll val, int x) {
    for (; x <= n; x += x & -x) bit[x] += val;
}

ll get(int x) {
    ll ret = 0;
    for (; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        add(i, i);
    }
    for (int i = n; i >= 1; i--) {
        int l = 0, r = n, pos = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(mid) <= s[i]) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        pos++;
        ans[i] = pos;
        add(-pos, pos);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
