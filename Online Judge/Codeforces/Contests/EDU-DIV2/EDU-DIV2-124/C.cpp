#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(2), b(2);
    set<long long> A, B;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> a[0];
        } else if (i == n - 1) {
            cin >> a[1];
        } else {
            long long x;
            cin >> x;
            A.emplace(x);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> b[0];
        } else if (i == n - 1) {
            cin >> b[1];
        } else {
            long long x;
            cin >> x;
            B.emplace(x);
        }
    }

    auto getClosest = [&](long long x, set<long long>& st) -> long long {
        auto it = st.upper_bound(x);
        long long ret = LLONG_MAX;
        if (it != st.end()) {
            ret = min(ret, abs(*it - x));
        }
        if (it != st.begin()) {
            --it;
            ret = min(ret, abs(*it - x));
        }
        return ret;
    };

    long long ans = LLONG_MAX;
    for (int it = 0; it < 2; it++) {
        ans = min(ans, 
            min(abs(a[0] - b[0]), getClosest(a[0], B) + getClosest(b[0], A)) + 
            min(abs(a[1] - b[1]), getClosest(a[1], B) + getClosest(b[1], A))
        );
        for (int rep = 0; rep < 2; rep++) {
            ans = min(ans, abs(a[0] - b[0]) + abs(a[0] - b[1]) + min({getClosest(a[1], B), abs(a[1] - b[0]), abs(a[1] - b[1])}));
            ans = min(ans, abs(b[0] - a[0]) + abs(b[0] - a[1]) + min({getClosest(b[1], A), abs(b[1] - a[0]), abs(b[1] - a[1])}));
            swap(a[0], a[1]);
        }
        swap(b[0], b[1]);
    }
    cout << ans << '\n';
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