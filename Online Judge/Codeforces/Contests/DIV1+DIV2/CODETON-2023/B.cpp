#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> vis;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    deque<int> ans;
    while (n > 1) {
        int x = n;
        n = n / 2;
        if (n % 2 == 0) {
            n = n + 1;
        }
        if (x == 2 * n - 1) {
            ans.emplace_front(1);
        } else if (x == 2 * n + 1) {
            ans.emplace_front(2);
        } else {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
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