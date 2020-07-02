#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const string alf = "abcdefghijklmnopqrstuvwxyz";

int tc;
int n, m;
char a[N][N];
char ans[N];

bool check() {
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != ans[j]) ++cnt;
            if (cnt == 2) return false;
        }
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) ans[j] = a[i][j];
            for (int k = 1; k <= m; k++) {
                for (int x = 0; x < 26; x++) {
                    ans[k] = alf[x];
                    if (check()) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
                ans[k] = a[i][k];
            }
            if (flag) break;
        }
        if (flag) {
            for (int j = 1; j <= m; j++) cout << ans[j];
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}