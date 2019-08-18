#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n;
ll v[N], t[N], ans[N], pre[N], cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + t[i];
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] < t[i]) {
            ans[i] += v[i];
            continue;
        }
        int l = i, r = n, pos = i - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (v[i] >= pre[mid] - pre[i - 1]) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        ll cur = v[i] - (pre[pos] - pre[i - 1]);
        ans[pos + 1] += cur;
        int le = i, ri = pos;
        cnt[le]++;
        cnt[ri + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] + t[i] * cnt[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
