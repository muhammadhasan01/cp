#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

const int N = 1e5 + 5;
int n;
pair<ld, ld> p[N];

bool cmpr(pair<ld, ld> a, pair<ld, ld> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        if (p[i].first < p[i].second) swap(p[i].first, p[i].second);
    }
    sort(p + 1, p + 1 + n, cmpr);
    ld ans = 0;
    set<ld> st;
    for (int i = n; i >= 1; i--) {
        ans = max(ans, p[i].first * (p[i].second / 2.0));
        if (i != n) {
            auto it = st.upper_bound(p[i].second);
            if (it == st.begin() || it != st.end()) {
                ans = max(ans, p[i].first * p[i].second);
            } else {
                ans = max(ans, p[i].first * *(--it));
            }
        }
        st.insert(p[i].second);
    }
    cout << fixed << setprecision(1) << ans << '\n';

    return 0;
}
