#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> lenz(3);
        for (int i = 0; i < 3; i++) {
            cin >> lenz[i];
        }
        vector<vector<long long>> gems;
        for (int i = 0; i < 3; i++) {
            vector<long long> cur(lenz[i]);
            for (int j = 0; j < lenz[i]; j++) {
                cin >> cur[j];
            }
            sort(cur.begin(), cur.end());
            gems.push_back(cur);
        }
        long long ans = 2e18;
        for (int i = 0; i < 3; i++) {
            int now = i;
            for (auto& x : gems[i]) {    
                vector<vector<long long>> temp;
                for (int j = 0; j < 3; j++) {
                    if (j == now) continue;
                    vector<long long> cur;
                    int pos = lower_bound(gems[j].begin(), gems[j].end(), x) - gems[j].begin();
                    if (pos < lenz[j]) cur.push_back(gems[j][pos]);
                    if (pos - 1 >= 0) cur.push_back(gems[j][pos - 1]);
                    temp.push_back(cur);
                }
                for (auto& y : temp[0]) {
                    for (auto& z : temp[1]) {
                        ans = min(ans, (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z));
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}