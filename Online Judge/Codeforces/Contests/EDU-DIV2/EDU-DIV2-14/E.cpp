#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long>> matrix;

const int M = 1e9 + 7;
const int N = 1e2 + 5;

int n;
long long a[N];
long long k;
matrix mat;

void upd(long long& x, long long y) {
    x = (x + y) % M;
}

matrix mul(const matrix& a, const matrix& b) {
    matrix c;
    c.assign(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                upd(c[i][j], ((a[i][k] % M) * (b[k][j] % M)) % M);
            }
        }
    }
    return c;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mat.assign(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long val = (a[i] ^ a[j]);
            if (__builtin_popcountll(val) % 3 != 0) continue;
            mat[i][j] = mat[j][i] = 1;
        }
    }
    matrix I;
    I.assign(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        I[i][i] = 1;
    --k;
    while (k > 0) {
        if (k & 1) I = mul(I, mat);
        k >>= 1;
        mat = mul(mat, mat);
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            upd(res, I[i][j]);
        }
    }
    cout << res << '\n';

    return 0;
}