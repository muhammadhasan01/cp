#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, bool> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            mp[v[i]] = true;
        } else if (v[i] < 0) {
            int x = -v[i];
            if (mp.count(x) == 0) {
                ++ans;
            }
            mp.erase(x);
        }
    }
    cout << ans << '\n';
    
    return 0;
}