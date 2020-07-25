#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 25;

int tc;
int n;
char a[N], b[N];
int cnt[K][K];

void solve() {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] < a[i]) {
            cout << -1 << '\n';
            return;
        }
        cnt[(int) (a[i] - 'a' + 1)][(int) (b[i] - 'a' + 1)]++;
    }
    int res = 0;
    for (int x = 2; x <= 20; x++) {
        for (int y = x - 1; y >= 1; y--) {
            if (cnt[y][x] == 0) continue;
            ++res;
            for (int k = x + 1; k <= 20; k++) {
                cnt[x][k] += cnt[y][k];
                cnt[y][k] = 0;
            }
        }
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--)
        solve();

    return 0;
}