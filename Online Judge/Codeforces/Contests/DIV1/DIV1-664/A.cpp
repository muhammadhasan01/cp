#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, d, m;
vector<int> v[2];
int len[2];
vector<long long> pre[2];

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[(x > m)].emplace_back(x);
    }
    for (int it = 0; it < 2; it++) {
        len[it] = v[it].size();
        sort(v[it].begin(), v[it].end(), greater<int>());
        pre[it].resize(len[it]);
        for (int j = 0; j < len[it]; j++) {
            pre[it][j] = (j == 0 ? v[it][j] : (1LL) * v[it][j] + pre[it][j - 1]);
        }
    }
    long long ans = 0;
    for (int i = 0; i <= len[0]; i++) {
        int num = min(len[1], ceil(len[1] + i, d + 1));
        int mun = len[0] - i;
        long long res = 0;
        if (mun > 0) res += pre[0][mun - 1];
        if (num > 0) res += pre[1][num - 1];
        ans = max(ans, res);
    }
    cout << ans << '\n';

    return 0;
}