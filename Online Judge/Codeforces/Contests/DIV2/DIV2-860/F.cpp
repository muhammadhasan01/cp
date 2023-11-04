#include <bits/stdc++.h>

using namespace std;

const int N = 205;

bool dp[N][N][N];
tuple<int, int, int> par[N][N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }
    vector<int> order(k);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int& i, int& j) {
        return s[i] < s[j]; 
    });
    vector<vector<int>> ans(k);
    for (int id = 0; id < k - 1; id++) {
        int idx = order[id];
        int num = s[idx];
        int len = 2 * num - 1;
        vector<int> vals(len + 1);
        for (int i = 1; i <= len; i++) {
            vals[i] = a.back();
            a.pop_back();
        }
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= num; j++) {
                for (int r = 0; r < num; r++) {
                    dp[i][j][r] = false;
                }
            }
        }
        dp[0][0][0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < min(i, num); j++) {
                for (int r = 0; r < num; r++) {
                    if (!dp[i - 1][j][r]) {
                        continue;
                    }
                    if (!dp[i][j][r]) {
                        dp[i][j][r] = true;
                        par[i][j][r] = make_tuple(i - 1, j, r);
                    }
                    int ci = i;
                    int cj = j + 1;
                    int cr = (r + vals[i]) % num;
                    if (!dp[ci][cj][cr]) {
                        dp[ci][cj][cr] = true;
                        par[ci][cj][cr] = make_tuple(i - 1, j, r);
                    }
                }
            }
        }
        int pi = -1;
        for (int i = len; i >= 1; i--) {
            if (dp[i][num][0]) {
                pi = i;
                break;
            }
        }
        assert(pi != -1);
        int pj = num;
        int pr = 0;
        vector<bool> taken(len + 1);
        while (pi > 0) {
            auto [ni, nj, nr] = par[pi][pj][pr];
            if (pj == nj + 1) {
                taken[pi] = true;
            }
            pi = ni, pj = nj, pr = nr;
        }
        for (int i = 1; i <= len; i++) {
            if (taken[i]) {
                ans[idx].emplace_back(vals[i]);
            } else {
                a.emplace_back(vals[i]);
            }
        }
    }
    int last = order.back();
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    int value = s[last] - (sum % s[last]);
    a.emplace_back(value);
    ans[last] = a;
    cout << value << '\n';
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < s[i]; j++) {
            cout << ans[i][j] << " \n"[j == s[i] - 1];
        }
    }
    
    return 0;
}