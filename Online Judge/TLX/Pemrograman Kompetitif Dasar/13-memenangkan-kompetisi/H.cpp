#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    set<pair<int, int>> st;
    int ans = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        int t, v;
        cin >> t >> v;
        pair<int, int> cur = make_pair(t, v);
        int prev = mp.count(cur) > 0 ? mp[cur] : -1;
        if (prev >= pos) {
            if (st.count(cur) > 0) {
                ++ans;
                pos = i;
                st.clear();
            } else {
                st.insert(cur);
            }
        }
        mp[cur] = i;
    }
    if (!st.empty()) {
        ++ans;
    }
    cout << ans << '\n';
    
    return 0;
}