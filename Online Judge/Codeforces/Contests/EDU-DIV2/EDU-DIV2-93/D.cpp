#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int len[3];
vector<int> val[3];
int memo[N][N][N];

int DP(int x, int y, int z) {
    if (memo[x][y][z] != -1) return memo[x][y][z];
    int ret = 0;
    if (x < len[0] && y < len[1]) ret = max(ret, val[0][x] * val[1][y] + DP(x + 1, y + 1, z));
    if (x < len[0] && z < len[2]) ret = max(ret, val[0][x] * val[2][z] + DP(x + 1, y, z + 1));
    if (y < len[1] && z < len[2]) ret = max(ret, val[1][y] * val[2][z] + DP(x, y + 1, z + 1));
    return memo[x][y][z] = ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < 3; i++)
        cin >> len[i];
    for (int it = 0; it < 3; it++) {
        val[it].resize(len[it]);
        for (int i = 0; i < len[it]; i++) {
            cin >> val[it][i];
        }
        sort(val[it].begin(), val[it].end(), greater<int>());
    }
    cout << DP(0, 0, 0) << '\n';

    return 0;
}