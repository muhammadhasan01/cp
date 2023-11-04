#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto getPipes = [&](int t) -> int {
        vector<long long> a(v.begin(), v.end());
        vector<bool> done(n);
        queue<int> q;
        int ret = 0;
        long long cur = 0;
        for (int i = 0; i < n; ) {
            if (!done[i]) {
                q.emplace(i);
            }
            if (cur < a[i]) {
                if (done[i]) {
                    return -1;
                }
                int x = q.front();
                q.pop();
                done[x] = true;
                ret++;
                a[i] -= cur;
                cur = t;
                continue;
            }

            cur -= a[i];
            i++;
        }
        return ret;
    };

    // getPipes(90);

    vector<tuple<int, int, int>> pre;
    for (int s = 1; s < INF; ) {
        int cur = getPipes(s);
        int l = s, r = INF, e = s;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (getPipes(mid) == cur) {
                l = mid + 1;
                e = mid;
            } else {
                r = mid - 1;
            }
        }
        pre.emplace_back(s, e, cur);
        s = e + 1;
    }
    int len = (int) pre.size();
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int l = 0, r = len - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get<0>(pre[mid]) <= t) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << get<2>(pre[at]) << '\n';
    }
    
    return 0;
}