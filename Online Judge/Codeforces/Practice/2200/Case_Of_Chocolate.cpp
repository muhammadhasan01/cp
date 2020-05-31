#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, x, y, ans;
    char cc;
    cin >> n >> q;
    map<int, pair<char, int>> mp;
    mp[0] = make_pair('U', n + 1);
    mp[n + 1] = make_pair('L', n + 1);
    while (q--) {
        cin >> x >> y >> cc;
        auto it = mp.lower_bound(x);
        if (it->first == x) {
            cout << 0 << '\n';
            continue;
        }
        if (cc == 'L') it--;
        ans = abs(it->first - x);
        if (it->second.first == cc) ans += it->second.second;
        mp[x] = make_pair(cc, ans);
        cout << ans << '\n'; 
    }
   
    return 0;
}