#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            int pos = -1;
            for (int it = 0; it < k; it++) {
                if (x == p[it]) {
                    pos = it;
                    break;
                }
            }
            ans += (pos + 1);
            p.erase(p.begin() + pos);
            p.insert(p.begin(), x);
        }
    }
    cout << ans << '\n';

    return 0;
}