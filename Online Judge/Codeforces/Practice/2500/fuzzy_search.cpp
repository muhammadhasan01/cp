#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 4;

map<char, int> mp = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};

int n, m, k;
int s[N], t[N];
int cnt[4][N];
bitset<N> ans, b[K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        s[i] = mp[cc];
    }
    for (int i = 0; i < m; i++) {
        char cc;
        cin >> cc;
        t[i] = mp[cc];
    }
    for (int i = 0; i < n; i++) {
        cnt[s[i]][max(0, i - k)]++;
        cnt[s[i]][min(n, i + k + 1)]--;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) cnt[i][j] += cnt[i][j - 1];
            if (cnt[i][j] > 0) {
                b[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        ans &= b[t[i]] >> i;
    }
    cout << ans.count() << '\n';

    return 0;
}