#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<pair<int, int>, int> fst;
    map<pair<int, int>, int> lst;
    vector<pair<int, int>> pre(n + 1);
    fst[{0, 0}] = 0;
    lst[{0, 0}] = 0;
    for (int i = 1, x = 0, y = 0; i <= n; i++) {
        if (s[i - 1] == 'L') {
            x--;
        } else if (s[i - 1] == 'R') {
            x++;
        } else if (s[i - 1] == 'U') {
            y++;
        } else if (s[i - 1] == 'D') {
            y--;
        }
        pre[i] = {x, y};
        if (!fst.count(pre[i])) {
            fst[pre[i]] = i;
        }
        lst[pre[i]] = i;
    }
    vector<pair<int, int>> suf(n + 2);
    map<pair<int, int>, set<int>> st;
    for (int i = n, x = 0, y = 0; i >= 1; i--) {
        if (s[i - 1] == 'L') {
            x--;
        } else if (s[i - 1] == 'R') {
            x++;
        } else if (s[i - 1] == 'U') {
            y++;
        } else if (s[i - 1] == 'D') {
            y--;
        }
        suf[i] = {x, y};
        st[suf[i]].emplace(i);
    }

    auto answerQuery = [&](int x, int y, int l, int r) -> bool {
        pair<int, int> cur = {x, y};
        if (fst.count(cur) && fst[cur] < l) {
            return true;
        }
        if (lst.count(cur) && lst[cur] > r) {
            return true;
        }
        pair<int, int> need = {
            x - pre[l - 1].first + suf[r + 1].first,
            y - pre[l - 1].second + suf[r + 1].second
        };
        if (st.count(need)) {
            auto& S = st[need];
            auto it = S.lower_bound(l);
            if (it != S.end() && *it <= r) {
                return true;
            }
        }
        return false;
    };

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << (answerQuery(x, y, l, r) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}