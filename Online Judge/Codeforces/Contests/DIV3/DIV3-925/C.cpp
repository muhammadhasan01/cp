#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto work = [&](int x) -> int {
        int fst = n + 1, lst = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != x) {
                fst = min(fst, i);
                lst = max(lst, i);
            }
        }
        if (fst > lst) {
            return 0;
        }
        return lst - fst + 1;
    };

    cout << min(work(a[0]), work(a[n - 1])) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}