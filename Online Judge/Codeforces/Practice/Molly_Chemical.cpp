#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e15;
int n, k;
int a[N];
pair<long long, int> pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        pre[i].first = pre[i - 1].first + (1LL) * a[i];
        pre[i].second = i;
    }
    sort(pre, pre + 1 + n);
    vector<long long> v;
    long long el = 1;
    if (abs(k) > 1) {
        while (abs(el) < inf) {
            v.push_back(el);
            el *= k;
        }
    } else if (k == 0) {
        v.push_back(0);
    } else if (k == 1) {
        v.push_back(1);
    } else if (k == -1) {
        v.push_back(-1);
        v.push_back(1);
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        for (auto e : v) {
            long long tgt = pre[i].first + e;
            if (tgt > inf) continue;
            int l = 0, r = n, low = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[mid].first >= tgt) {
                    r = mid - 1;
                    low = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (low == -1 || pre[low].first != tgt) continue;
            l = 0, r = n;
            int high = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[mid].first <= tgt) {
                    l = mid + 1;
                    high = mid;
                } else {
                    r = mid - 1;
                }
            }
            int tgtidx = pre[i].second;
            l = low, r = high;
            int pos = high + 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[mid].second > tgtidx) {
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans += (high - pos + 1);
        }
    }
    cout << ans << '\n';

    return 0;
}
