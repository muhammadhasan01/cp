#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int res = x * y;
    res = min(res, (n - x + 1) * y);
    res = min(res, (n - x + 1) * (m - y + 1));
    res = min(res, x * (m - y + 1));
    int cur = n * m - res;
    if (cur <= res) {
        cout << "I don't wanna do this anymore!" << '\n';
        return 0;
    }
    cout << res << '\n';

    return 0;
}