#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> last(n + 1);
    vector<int> lft(n + 1);
    vector<int> len(n + 1);
    for (int i = 1; i <= n; i++) {
        lft[i] = max(lft[i - 1], 1 + last[a[i]]);
        last[a[i]] = i;
        len[i] = i - lft[i] + 1;
    }
    vector<pair<int, int>> pref(n + 2);
    for (int i = 1; i <= n; i++) {
        pref[i] = max(pref[i - 1], {len[i], i});
    }
    vector<pair<int, int>> suff(n + 2);
    for (int i = n; i >= 1; i--) {
        suff[i] = max(suff[i + 1], {len[i], i});
    } 

    auto can = [&](int len, pair<int, int>& X, pair<int, int>& Y) -> bool {
        int at = -1;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (suff[mid].first >= len) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at == -1) {
            return false;
        }
        int pos = suff[at].second - len;
        if (pref[pos].first < len) {
            return false;
        }
        X = {pref[pos].second - len + 1, pref[pos].second};
        Y = {suff[at].second - len + 1, suff[at].second};
        return true;
    };

    pair<int, int> X, Y;
    int l = 1, r = n / 2, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid, X, Y)) {
            l = mid + 1;
            at = mid;
        } else {
            r = mid - 1;
        }
    }
    can(at, X, Y);
    cout << X.first << ' ' << X.second << ' ' << Y.first << ' ' << Y.second << '\n';

    return 0;
}