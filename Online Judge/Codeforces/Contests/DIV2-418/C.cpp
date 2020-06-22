#include <bits/stdc++.h>

using namespace std;

const int N = 1505;
const int K = 26;

int n, q;
int pre[N][K + 5];
char s[N];

bool can(int x, int y, int z) {
    for (int i = 1; i <= n - x + 1; i++) {
        int res = pre[i + x - 1][y] - pre[i - 1][y];
        if (x - res <= z) return true;
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < K; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][(int) (s[i] - 'a')]++;
    }
    cin >> q;
    while (q--) {
        int x;
        char cc;
        cin >> x >> cc;
        int val = cc - 'a';
        int l = 1, r = n, ans = 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid, val, x)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}