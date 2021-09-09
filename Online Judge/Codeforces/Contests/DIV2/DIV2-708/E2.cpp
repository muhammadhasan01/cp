#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 1e7 + 5;

int freq[N];
int last_prime[N];

void solve() {
    int n, k;
    cin >> n >> k;
    auto get_val = [&](int x) -> int {
        int ret = 1;
        while (x > 1) {
            int pr = last_prime[x];
            int bit = 0;
            while (x % pr == 0) {
                x /= pr;
                bit ^= 1;
            }
            if (bit) {
                ret *= pr;
            }
        }
        return ret;
    };
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = get_val(a[i]);
    }
    vector<vector<int>> left(n + 1, vector<int>(k + 1));
    for (int j = 0; j <= k; j++) {
        for (int i = n - 1, l = n, now = 0; i >= 0; i--) {
            while (l - 1 >= 0 && now + (freq[a[l - 1]] > 0) <= j) {
                l--;
                now += (freq[a[l]] > 0);
                freq[a[l]]++;
            }
            left[i + 1][j] = l;
            if (freq[a[i]] > 1) {
                now--;
            }
            freq[a[i]]--;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j > 0) {
                dp[i][j] = dp[i][j - 1];
            }
            for (int x = 0; x <= j; x++) {
                dp[i][j] = min(dp[i][j], dp[left[i][x]][j - x] + 1);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (last_prime[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            last_prime[j] = i;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}