#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pli;

const int N = 1e5 + 5;
int x[30];
string s;
int n;
long long dp[N];
vector<pli> store[30];
vector<pli> erots[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 26; i++) {
        cin >> x[i];
    }
    cin >> s;
    n = s.length();
    s = '#' + s;
    for (int i = 1; i <= n; i++) {
        dp[i] = x[s[i] - 'a'] + dp[i - 1];
    }
    for (int i = 2; i <= n; i++) {
        int pos = s[i - 1] - 'a';
        store[pos].push_back({dp[i - 1], i});
    }
    for (int i = 1; i <= n - 1; i++) {
        int pos = s[i + 1] - 'a';
        erots[pos].push_back({dp[i], i + 1});
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        if (erots[i].empty() || store[i].empty()) continue;
        sort(erots[i].begin(), erots[i].end());
        for (auto e : store[i]) {
            int l = 0, r = erots[i].size() - 1, left = erots[i].size() - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (erots[i][mid].first >= e.first) {
                    r = mid - 1;
                    left = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (erots[i][left].first != e.first) continue;
            l = 0, r = erots[i].size() - 1;
            int right = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (erots[i][mid].first <= e.first) {
                    l = mid + 1;
                    right = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (left > right) continue;
            int pos = right + 1;
            l = left, r = right;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (erots[i][mid].second >= e.second) {
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans += (1LL) * (right - pos + 1);
        }
    }
    cout << ans << '\n';

    return 0;
}
