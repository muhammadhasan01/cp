#include <bits/stdc++.h>

using namespace std;

const long long MOD = 26101991;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<long long>> minstep(n + 1, vector<long long>(n + 1));
    vector<vector<long long>> optways(n + 1, vector<long long>(n + 1));
    vector<vector<long long>> ways(n + 1, vector<long long>(n + 1));
    for (int len = 2; len <= n + 1; len++) {
        for (int i = 0; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) {
                break;
            }
            if (i + 1 == j) {
                ways[i][j] = 1;
                minstep[i][j] = 0;
                optways[i][j] = 1;
            } else {
                minstep[i][j] = LLONG_MAX;
                for (int k = i + 1; k < j; k++) {
                    ways[i][j] += ways[i][k] * ways[k][j];
                    ways[i][j] %= MOD;
                    long long curstep = minstep[i][k] + minstep[k][j] + (1LL * a[i] * a[k] * a[j]);
                    if (curstep < minstep[i][j]) {
                        minstep[i][j] = curstep;
                    }
                }
                for (int k = i + 1; k < j; k++) {
                    long long curstep = minstep[i][k] + minstep[k][j] + (1LL * a[i] * a[k] * a[j]);
                    if (curstep == minstep[i][j]) {
                        optways[i][j] += optways[i][k] * optways[k][j];
                        optways[i][j] %= MOD;
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    if (q == 1) {
        cout << minstep[0][n] << '\n';
    } else if (q == 2) {
        cout << optways[0][n] << '\n';
    } else if (q == 3) {
        cout << ways[0][n] << '\n';
    }

    return 0;
}