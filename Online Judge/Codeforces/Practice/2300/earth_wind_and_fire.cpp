#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<tuple<int, int, int>> ans;
    long long pref = 0;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        auto [av, idx] = a[i];
        auto [bv, _] = b[i];
        int dif = bv - av;
        pref += dif;
        if (pref < 0) {
            cout << "NO" << '\n';
            return 0;
        }
        if (dif == 0) {
            continue;
        } else if (dif > 0) {
            st.emplace(dif, idx);
        } else if (dif < 0) {
            dif = -dif;
            while (true) {
                if (st.empty()) {
                    cout << "NO" << '\n';
                    return 0;
                }
                auto [sdif, sidx] = st.top();
                st.pop();
                ans.emplace_back(sidx, idx, min(sdif, dif));
                if (dif == sdif) {
                    break;
                } else if (sdif > dif) {
                    st.emplace(sdif - dif, sidx);
                    break;
                } else if (sdif < dif) {
                    dif -= sdif;
                }
            }
        }
    }
    if (pref != 0) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    cout << ans.size() << '\n';
    for (auto& [i, j, d] : ans) {
        cout << i << ' ' << j << ' ' << d << '\n';
    }
    
    return 0;
}