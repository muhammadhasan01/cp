#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n, m;
bool col[N], row[N];
int a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 1) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        int currow = 0, curcol = 0;
        for (int i = 1; i <= n; i++) {
            if (row[i] == 0) currow++;    
        }
        for (int j = 1; j <= m; j++) {
            if (col[j] == 0) curcol++;
        }
        int cur = min(currow, curcol);
        cout << (cur & 1 ? "Ashish" : "Vivek") << '\n';
    }

    return 0;
}