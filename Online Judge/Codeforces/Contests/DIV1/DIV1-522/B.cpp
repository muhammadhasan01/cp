#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n;
int p[N];
int cnt[N];
int ans = 1;
vector<pair<int, int>> v;
int len;

void check(int pos) {
    int x = v[pos].first, y = v[pos].second;
    int res = x * y;
    vector<vector<bool>> dp(y + 1, vector<bool>(res + 1));
    for (int i = 0; i < len; i++) {
        if (i == pos) continue;
        if (v[i].first > res) continue;
        for (int it = 0; it < v[i].second; it++) {
            for (int j = y; j >= 2; j--) {
                for (int k = 0; k <= res; k++) {
                    int cur = k + v[i].first;
                    if (cur > res) continue;
                    if (dp[j - 1][k]) {
                        dp[j][cur] = 1;
                    }
                }
            }
            dp[1][v[i].first] = 1;
        }   
    }
    for (int i = 1; i <= y; i++) {
        if (dp[i][x * i]) {
            return;
        }
        ans = max(ans, i);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        cnt[p[i]]++;
    }
    for (int i = 1; i < N; i++) {
        if (cnt[i]) {
            v.emplace_back(i, cnt[i]);
        }
    }
    len = v.size();
    if (len == 2) {
        cout << n << '\n';
        return 0;
    }
    for (int i = 0; i < len; i++) {
        check(i);
    }
    cout << ans << '\n';

    return 0;
}