#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using pld = pair<long double, long double>;

const ld INF = 1e9;
const ld EPS = 1e-6;

void solve(int n) {
    vector<pld> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end(), [&](auto& l, auto& r) {
        return l.second < r.second;
    });

    auto getDist = [&](pld A, pld B) -> ld {
        ld dx = A.second - B.second;
        ld dy = A.first - B.first;
        return sqrtl(dx * dx + dy * dy);
    };

    ld best = INF;
    set<pld> st;
    st.emplace(p[0]);
    pld A = p[0];
    pld B = p[1];
    for (int l = 0, r = 1; r < n; r++) {
        while (l < r && p[r].second - p[l].second - best > EPS) {
            st.erase(p[l++]);
        }
        for (auto it = st.lower_bound({p[r].first - best, p[r].second - best}); it != st.end(); it++) {
            if (it->first - p[r].first - best > EPS) {
                break;
            }
            ld dist = getDist(*it, p[r]);
            if (dist - best < EPS) {
                A = *it;
                B = p[r];
                best = dist;
            }
        }
        st.emplace(p[r]);
    }
    cout << fixed << setprecision(2);
    cout << A.second << " " << A.first << " " << B.second << " " << B.first << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        solve(n);
    }
    
    return 0;
}