#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    multiset<int> A, B;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.emplace(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        B.emplace(x);
    }

    auto getLog = [&](int x) -> int {
        int ret = 0;
        while (x > 0) {
            x /= 10;
            ret++;
        }
        return ret;
    };

    int ans = 0;
    while (true) {
        if (A.empty() || B.empty()) {
            break;
        }
        int x = *A.rbegin();
        int y = *B.rbegin();
        if (x == y) {
            A.erase(A.find(x));
            B.erase(B.find(y));
        } else if (x > y) {
            A.erase(A.find(x));
            A.emplace(getLog(x));
            ++ans;
        } else {
            B.erase(B.find(y));
            B.emplace(getLog(y));
            ++ans;
        }
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