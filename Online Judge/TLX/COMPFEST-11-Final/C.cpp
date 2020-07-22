#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 30;

int tc;
int n;
int cnt[M][M];
int a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        a[i] = (int) (x - 'a');
    }
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        b[i] = (int) (x - 'a');
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) continue;
        cnt[a[i]][b[i]]++;
    }
    int res = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            res += max(cnt[i][j], cnt[j][i]);
        }
    }
    cout << res << '\n';
    memset(cnt, 0, sizeof(cnt));
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