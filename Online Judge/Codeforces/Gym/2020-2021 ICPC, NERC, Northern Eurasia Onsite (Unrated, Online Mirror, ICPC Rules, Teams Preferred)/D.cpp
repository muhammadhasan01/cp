#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const long double EPS = 1e-12;
const int N = 1e5 + 5;
const int D = 10;

int n, d;
int a[N];
long double dp[N][D];
pair<int, int> go[N][D];

template<typename T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            dp[i][j] = -INF;
            go[i][j] = make_pair(-1, -1);
        }
    }
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            if (dp[i][j] < 0) continue;
            if (chmax(dp[i + 1][j], dp[i][j])) {
                go[i + 1][j] = go[i][j];
            }
            int k = (j * a[i]) % D;
            if (chmax(dp[i + 1][k], dp[i][j] + log(a[i]))) {
                go[i + 1][k] = make_pair(i, j);
            }
        }
    }
    if (dp[n][d] < -EPS) {
        cout << -1 << '\n';
        return 0;
    }
    if (abs(dp[n][d]) < EPS) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                cout << 1 << '\n';
                cout << 1 << '\n';
                return 0;
            }
        }
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans;
    {
        int i = n, j = d;
        while (true) {
            auto [b_i, b_j] = go[i][j];
            if (b_i == -1) break; 
            i = b_i, j = b_j;
            ans.emplace_back(a[i]);
        }
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }

    return 0;
}