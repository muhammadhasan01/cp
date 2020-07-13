#include <bits/stdc++.h>

using namespace std;

const int N = 155;

int tc;
int n, m;
int a[N][N];
int cnt[N][N];

long long solve() {
    cin >> n >> m;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            nums.emplace_back(a[i][j]);
        }
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = lower_bound(nums.begin(), nums.end(), a[i][j]) - nums.begin();
        }
    }
    long long ret = 0;
    int len = nums.size();
    for (int x = 0; x < len; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j] != x) continue;
                for (int k = j + 1; k <= m; k++) {
                    if (a[i][k] != x) continue;
                    ret += (1LL) * cnt[j][k]++;
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                cnt[j][k] = 0;
            }
        }
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}