#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    set<int> A, B;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.emplace(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        B.emplace(x);
    }
    int ans = INT_MAX;
    for (int x : A) {
        auto it = B.lower_bound(x);
        if (it != B.end()) {
            ans = min(ans, abs(x - *it));
        }
        if (it != B.begin()) {
            ans = min(ans, abs(x - *prev(it)));
        }
    }
    cout << ans << '\n';
    
    return 0;
}