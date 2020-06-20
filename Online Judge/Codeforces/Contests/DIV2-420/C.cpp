#include <bits/stdc++.h>

using namespace std;

int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n = 2 * n;
    vector<pair<char, int>> v;
    int now = 1;
    for (int it = 1; it <= n; it++) {
        string op;
        int x;
        cin >> op;
        if (op[0] == 'a') {
            cin >> x;
            v.emplace_back(op[0], x);
        } else {
            if (v.back().second == now) v.pop_back();
            else v.emplace_back(op[0], now);
            ++now;
        }
    }
    int len = v.size();
    int ans = 0;
    for (int i = 1; i < len; i++) {
        if (v[i].first == 'r' && v[i - 1].first == 'a') ++ans;
    }
    cout << ans << '\n';

    return 0;
}