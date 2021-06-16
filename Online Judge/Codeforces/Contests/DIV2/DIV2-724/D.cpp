#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    multiset<int> ms;
    int previous = -1;

    auto check = [&](int x) -> bool {
        if (ms.empty()) {
            return true;
        }
        for (int rep = 0; rep < 2; rep++) {
            auto it = (rep == 0 ? ms.lower_bound(x) : ms.upper_bound(x));
            if (it != ms.end() && *it == previous) {
                return true;
            }
            if (it != ms.begin() && *prev(it) == previous) {
                return true;
            }
        }
        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (!check(b[i])) {
            cout << "NO" << '\n';
            return;
        }
        ms.emplace(b[i]);
        previous = b[i];
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}