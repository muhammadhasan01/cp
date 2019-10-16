#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int n;
int a[N][N], x[N];
long long ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        cin >> x[i];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[x[i]][x[j]] = min(a[x[i]][x[j]], a[x[i]][x[k]] + a[x[k]][x[j]]);
            }
        }
        long long res = 0;
        for (int i = 1; i <= k; i++){
            for (int j = 1; j <= k; j++) {
                res += (1LL) * a[x[i]][x[j]];
            }
        }
        ans[k] = res;
    }
    for (int i = n; i >= 1; i--) {
        cout << ans[i] << (i == 1 ? '\n' : ' ');
    }

    return 0;
}
