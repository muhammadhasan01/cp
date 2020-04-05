#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

struct st {
    int x, y, s;
};

int n, m;
char a[N][N];
int row[N][N], col[N][N];
int crow[N][N], ccol[N][N];
vector<st> ans;

bool can(int i, int j, int x) {
    int ui = i - x;
    int di = i + x;
    int lj = j - x;
    int rj = j + x;
    if (row[i][rj] - row[i][lj - 1] != rj - lj + 1) return false;
    if (col[di][j] - col[ui - 1][j] != di - ui + 1) return false;
    return true;
}

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            row[i][j] = row[i][j - 1] + (a[i][j] == '*');
        }
    }   
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            col[i][j] = col[i - 1][j] + (a[i][j] == '*');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') continue;
            int boundz = min(min(j, m - j + 1), min(i, n - i + 1)) - 1;
            int l = 1, r = boundz, at = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (can(i, j, mid)) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at == 0) continue;
            ans.push_back({i, j, at});
            crow[i][j - at]++, crow[i][j + at + 1]--;
            ccol[i - at][j]++, ccol[i + at + 1][j]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            crow[i][j] += crow[i][j - 1];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            ccol[i][j] += ccol[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') continue;
            if (ccol[i][j] > 0) continue;
            if (crow[i][j] > 0) continue;
            dismiss();
        }
    }
    cout << ans.size() << '\n';
    for (auto& e : ans) {
        cout << e.x << " " << e.y << " " << e.s << '\n';
    }

    return 0;
}