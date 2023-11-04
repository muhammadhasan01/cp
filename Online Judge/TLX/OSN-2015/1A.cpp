#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int sd, td, ls, lt, n;
    cin >> sd >> td >> ls >> lt >> n;
    int sm, tm;
    cin >> sm >> tm;

    auto ceil = [&](long long x, long long y) -> long long {
        return (x + y - 1) / y;
    };

    auto check = [&](int s, int t, int k) -> bool {
        return ceil(s, 1LL * k * lt + td) <= ceil(1LL * k * ls + sd, t);
    };

    auto getMinNeed = [&](int s, int t) -> int {
        int l = 0, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(s, t, mid)) {
                at = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return at;
    };

    vector<tuple<int, int, int, int>> a;
    for (int i = 2; i <= n; i++) {
        int s, t;
        cin >> s >> t;
        int minNeed = getMinNeed(s, t);
        if (minNeed != -1) {
            a.emplace_back(minNeed, i, s, t);
        }
    }
    int cur = 0;
    if (check(sm, tm, cur)) {
        cout << cur << '\n';
        return 0;
    }
    sort(a.begin(), a.end());
    vector<int> pos;
    for (auto [minNeed, i, s, t] : a) {
        if (minNeed > cur) {
            break;
        }
        ++cur;
        pos.emplace_back(i);
        if (check(sm, tm, cur)) {
            cout << cur << '\n';
            for (int p : pos) {
                cout << p << '\n';
            }
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}