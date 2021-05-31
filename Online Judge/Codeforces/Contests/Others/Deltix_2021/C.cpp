#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cur;

    auto output = [&]() -> void {
        int len = cur.size();
        for (int i = 0; i < len; i++) {
            cout << cur[i] << ".\n"[i == len - 1];
        }
    };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (cur.empty()) {
            cur.emplace_back(x);
        } else {
            if (x == 1) {
                cur.emplace_back(x);
            } else {
                while (cur.back() != x - 1) {
                    cur.pop_back();
                }
                cur.back() = x;
            }
        }
        output();
    }
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