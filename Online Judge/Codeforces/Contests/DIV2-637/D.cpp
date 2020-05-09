#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 7;
const int K = 10;
const vector<string> nums = {
    "1110111", "0010010", "1011101",
    "1011011", "0111010", "1101011",
    "1101111", "1010010", "1111111",
    "1111011"
};

int n, m;
char a[N][M + 5];
vector<pair<int, int>> v[N];
int dp[N][N];
int go[N][N];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[n - 1 - i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> vcnt(M + 1, -1);
        for (int k = 0; k < K; k++) {
            bool flag = true;
            int cnt = 0;
            for (int j = 0; j < M; j++) {
                if (a[i][j] == nums[k][j]) continue;
                if (a[i][j] == '1') {
                    flag = false;
                    break;
                }
                if (++cnt > m) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                vcnt[cnt] = k;
            }
        }
        for (int j = 0; j <= M; j++) {
            if (vcnt[j] != -1) {
                v[i].push_back({vcnt[j], j});
            }
        }
        if (v[i].empty()) dismiss();
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (auto& e : v[i]) {
                dp[i][e.second] = e.first;
            }
        } else {
            for (auto& e : v[i]) {
                for (int j = e.second; j <= m; j++) {
                    if (dp[i - 1][j - e.second] == -1) continue;
                    if (e.first > dp[i][j]) {
                        dp[i][j] = e.first;
                        go[i][j] = j - e.second;
                    }
                }
            }
        }
    }
    int i = n - 1, j = m;
    while (i >= 0) {
        int cur = dp[i][j];
        if (cur == -1) dismiss();
        cout << cur;
        j = go[i][j];
        i--;
    }
    cout << '\n';

    return 0;
}