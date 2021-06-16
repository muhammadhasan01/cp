#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, m;
char a[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<char> CC = {'R', 'W'};
    for (int it = 0; it < 2; it++) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char cc = CC[(i + j) % 2];
                if (a[i][j] == '.' || cc == a[i][j]) continue;
                ok = false;
                break;
            }
            if (!ok) break;
        }
        if (ok) {
            cout << "YES" << '\n';
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << CC[(i + j) % 2];
                }
                cout << '\n';
            }
            return;
        }
        swap(CC[0], CC[1]);
    }
    cout << "NO" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}