#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        if (r >= sum && sum >= l) {
            cout << sum << '\n';
            return 0;
        } else if (l >= sum) {
            cout << l << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}