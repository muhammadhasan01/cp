#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> lines(n);
    for (auto& [l, r, a, b] : lines) {
        cin >> l >> r >> a >> b;
        a = l;
    }
    sort(lines.begin(), lines.end(), [&](auto& lhs, auto& rhs) {
        return get<3>(lhs) > get<3>(rhs);
    });
    vector<pair<int, int>> ranges;
    int L = get<2>(lines[0]);
    int R = get<3>(lines[0]);
    for (int i = 1; i < n; i++) {
        auto& [l, r, a, b] = lines[i];
        if (b >= L) {
            L = min(L, a);
        } else {
            ranges.emplace_back(L, R);
            L = get<2>(lines[i]);
            R = get<3>(lines[i]);
        }
    }
    ranges.emplace_back(L, R);
    sort(ranges.begin(), ranges.end());
    int len = (int) ranges.size();

    auto getPosition = [&](int x) -> int {
        int ans = x;
        int l = 0, r = len - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ranges[mid].first <= x) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at != -1) {
            ans = max(ans, ranges[at].second);
        }
        return ans;
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << getPosition(x) << " \n"[i == q - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}