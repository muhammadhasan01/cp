#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;

int tc;
int n, k;
char s[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<int> pos;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            if (s[i] == '1') pos.emplace_back(i);
        }
        int last = -INF;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                last = i;
            } else {
                if (i - last <= k) continue;
                auto it = lower_bound(pos.begin(), pos.end(), i);
                if (it != pos.end() && *it - i <= k) continue;
                last = i;
                ++ans;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}