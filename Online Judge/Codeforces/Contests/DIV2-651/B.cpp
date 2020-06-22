#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int n, m;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        m = 2 * n;
        vector<int> odd, even;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            if (x & 1) {
                odd.emplace_back(i);
            } else {
                even.emplace_back(i);
            }
        }
        vector<pair<int, int>> ans;
        int len = odd.size();
        int cnt = 0;
        for (int i = 0; i < len - 1; i += 2) {
            if (cnt == n - 1) break;
            ans.emplace_back(odd[i], odd[i + 1]);
            ++cnt;
        }
        len = even.size();
        for (int i = 0; i < len - 1; i += 2) {
            if (cnt == n - 1) break;
            ans.emplace_back(even[i], even[i + 1]);
            ++cnt;
        }
        for (auto& e : ans) {
            cout << e.first << " " << e.second << '\n';
        }
    }

    return 0;
}