#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s, n;
    cin >> s >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> res;
    {
        int cur = v[0], cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cur != v[i]) {
                res.emplace_back(cur, cnt);
                cur = v[i];
            }
            cnt = cnt + 1;
        }
        res.emplace_back(cur, cnt);
    }
    int len = res.size();
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int l = 0, r = len - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (res[mid].second <= x) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at == len - 1) {
            cout << s << '\n';
        } else {
            cout << res[at + 1].first -  1 << '\n';
        }
    }

    return 0;
}