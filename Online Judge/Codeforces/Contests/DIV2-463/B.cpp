#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int q;
long long pre[N][10];
int par[N];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 9; i++) par[i] = i;

    for (int i = 1; i <= N - 5; i++) {
        int k = i;
        int prod = 1;
        while (k > 0) {
            int cur = k % 10;
            if (cur != 0) {
                prod *= cur;
            }
            k /= 10;
        }
        par[i] = prod;
        int x = find(prod);
        pre[i][x]++;
    }

    for (int t = 1; t <= 9; t++) {
        for (int i = 1; i <= N - 5; i++) {
            pre[i][t] += pre[i - 1][t];
        }
    }

    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << pre[r][k] - pre[l - 1][k] << '\n';
    }

    return 0;
}
