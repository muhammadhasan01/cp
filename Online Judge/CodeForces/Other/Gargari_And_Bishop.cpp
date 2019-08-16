#include<bits/stdc++.h>
using namespace std;

struct st{
    long long c;
    int x,y;
};

const int N = 2e3 + 5;
int n, a[N][N];
long long f[3][2 * N + 5];

st maks(st a, st b) {
    return (b.c > a.c ? b : a);
}

st get(int i, int j) {
    st ret;
    ret.x = i, ret.y = j;
    ret.c = f[0][n - (i - j)] + f[1][2 * n - i - j + 1] - (1LL) * a[i][j];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            int d1 = n - (i - j);
            int d2 = 2 * n - i - j + 1;
            f[0][d1] += (1LL) * a[i][j];
            f[1][d2] += (1LL) * a[i][j];
        }
    }

    st odd, even;
    odd.c = even.c = odd.x = even.x = odd.y = even.y = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) & 1) {
                odd = maks(odd, get(i, j));
            } else {
                even = maks(even, get(i, j));
            }
        }
    }
    cout << even.c + odd.c << '\n';
    cout << even.x << " " << even.y << " " << odd.x << " " << odd.y << '\n';


    return 0;
}
