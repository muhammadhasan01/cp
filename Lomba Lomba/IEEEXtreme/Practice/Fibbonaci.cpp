#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> matrix;

const int M = 1e9 + 7;
int tc;

matrix fib;
matrix id;

matrix mul(matrix a, matrix b, int m) {
    matrix c(m + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] += (a[i][k] % M) * (b[k][j] % M);
                c[i][j] %= M;
            }
        }
    }
    return c;
}

int get(int x) {
    if (x-- == 1) return 1;
    matrix ret = id, ffib = fib;
    while (x > 0) {
        if (x & 1) ret = mul(ffib, ret, 2);
        x >>= 1;
        ffib = mul(ffib, ffib, 2);
    }
    int gret = ret[0][0] * 1 + ret[0][1] * 2;
    return (gret % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fib = {{0, 1}, {1, 1}};
    id = {{1, 0}, {0, 1}};

    cin >> tc;
    while (tc--) {
        int m;
        cin >> m;
        cout << get(m) << '\n';
    }

    return 0;
}
