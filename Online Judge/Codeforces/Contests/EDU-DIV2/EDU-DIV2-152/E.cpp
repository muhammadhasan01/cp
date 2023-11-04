#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> MIN, MAX;
    set<pair<int, int>> st;
    MIN.emplace_back(0, -1);
    MAX.emplace_back(0, n + 1);
    st.emplace(0, 0);
    st.emplace(0, 1);
    int len = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (x < MIN.back().second) {
            auto pos = st.find({MIN.back().first, 0});
            auto prv = prev(pos);
            auto nxt = next(pos);
            len -= pos->first - prv->first;
            if (nxt != st.end() && nxt->second == 0) {
                len += nxt->first - prv->first;
            }
            st.erase(pos);
            MIN.pop_back();
        }
        while (x > MAX.back().second) {
            auto pos = st.find({MAX.back().first, 1});
            auto prv = prev(pos);
            auto nxt = next(pos);
            if (nxt != st.end() && nxt->second == 0) {
                len += pos->first - prv->first;
            }
            st.erase(pos);
            MAX.pop_back();
        }
        MIN.emplace_back(i, x);
        MAX.emplace_back(i, x);
        st.emplace(i, 0);
        st.emplace(i, 1);
        ++len;
        ans += len;
    }
    cout << ans - n << '\n';
    
    return 0;
}