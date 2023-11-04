#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<long long> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    auto check = [&](long long pos) -> bool {
        set<long long> st(x.begin(), x.end());
        for (int i = 0; i < n; i++) {
            long long L = pos - l[i];
            long long R = pos + l[i];
            auto it = st.lower_bound(L);
            if (it == st.end() || *it > R) {
                return false;
            }
            st.erase(it);
        }
        return true;
    };

    vector<long long> points;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long L = x[i] - l[j];
            long long R = x[i] + l[j];
            if (check(L)) {
                points.emplace_back(L);
            }
            if (check(R)) {
                points.emplace_back(R);
            }
        }
    }
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    int len = (int) points.size();
    long long ans = len;
    for (int i = 0; i + 1 < len; i++) {
        if (points[i] + 1 < points[i + 1] && check(points[i] + 1)) {
            ans += (points[i + 1] - points[i] - 1);
        } 
    }
    cout << ans << '\n';
    
    return 0;
}