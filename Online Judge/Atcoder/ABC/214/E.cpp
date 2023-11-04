#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    vector<int> points;
    for (auto& [l, r] : ranges) {
        cin >> l >> r;
        points.emplace_back(l);
        points.emplace_back(r);
    }
    map<int, vector<int>> in, out;
    for (int i = 0; i < n; i++) {
        auto& [l, r] = ranges[i];
        in[l].emplace_back(i);
        out[r].emplace_back(i);    
    }
    points.emplace_back(MAX + 1);
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    int cnt = 0;
    multiset<int> ms;
    for (int x = 1; x <= MAX; x++) {
        for (int i : in[x]) {
            ms.emplace(ranges[i].second);
        }
        if (ms.empty()) {
            x = *upper_bound(points.begin(), points.end(), x) - 1;
            continue;
        }
        ms.erase(ms.begin());
        ++cnt;
        for (int i : out[x]) {
            if (ms.empty()) {
                break;
            }
            auto it = ms.find(ranges[i].second);
            if (it != ms.end()) {
                ms.erase(it);
            }
        }
    }
    cout << (cnt == n ? "Yes" : "No") << '\n';
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