#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        int l = s;
        int r = s + d;
        intervals[i] = {l, r};
    }
    sort(intervals.begin(), intervals.end(), [&](auto& lhs, auto& rhs) {
        if (lhs.second != rhs.second) {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    });
    int ans = 0;
    int cur = 0;
    for (auto& [l, r] : intervals) {
        if (cur <= l) {
            ++ans;
            cur = r;
        }
    }
    cout << ans << '\n';
    
    return 0;
}