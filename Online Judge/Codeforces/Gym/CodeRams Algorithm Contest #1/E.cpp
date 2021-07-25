#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m;
char p[N][N];
long long a[N];
long long k;
vector<long long> v[N];

bool can(int x) {
    long long ret = 0;
    for (int j = 1; j <= m; j++) {
        int len = v[j].size();
        if (len == 0) {
            continue;
        }
        ret += v[j][min(len - 1, x - 1)];
    }
    return (ret >= k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (p[i][j] == '1') {
                v[j].emplace_back(a[i]);
            }
        }
        sort(v[j].begin(), v[j].end(), greater<>());
        int len = v[j].size();
        for (int i = 1; i < len; i++) {
            v[j][i] += v[j][i - 1];
        }
    }
    int l = 1, r = n, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            at = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << at << '\n';

    return 0;
}