#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (st.find({-cnt[x], x}) != st.end()) {
            st.erase({-cnt[x], x});
        }
        ++cnt[x];
        st.emplace(-cnt[x], x);
        cout << st.begin()->second << '\n';
    }
    
    return 0;
}