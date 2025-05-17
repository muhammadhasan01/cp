#include <bits/stdc++.h>

using namespace std;
using tiii = tuple<long long, int, int>;

const int N = 2e3 + 5;

int a[N][N];
long long pre[N * N];
long long suf[N * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i + j - 1] += a[i][j];
            suf[i + (n - j + 1) - 1] += a[i][j];
        }
    }

    auto getValue = [&](int i, int j) -> long long {
        return pre[i + j - 1] + suf[i + n - j] - a[i][j];
    };

    tuple<long long, int, int> X;
    tuple<long long, int, int> Y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tuple<long long, int, int> cur = make_tuple(getValue(i, j), i, j);
            if ((i + j) & 1) {
                X = max(X, cur);
            } else {
                Y = max(Y, cur);
            }
        }
    }

    auto [val1, i1, j1] = X;
    auto [val2, i2, j2] = Y;
    cout << val1 + val2 << '\n';
    cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << '\n';
    
    return 0;
}