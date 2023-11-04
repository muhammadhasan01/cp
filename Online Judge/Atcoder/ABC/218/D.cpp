#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }
    sort(p.begin(), p.end());
    set<pair<int, int>> st(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].first < p[j].first && p[i].second < p[j].second) {
                if (st.count({p[j].first, p[i].second}) && st.count({p[i].first, p[j].second})) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}