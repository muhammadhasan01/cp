#include <bits/stdc++.h>

using namespace std;

const int R = 4;
const int N = 55;

struct st {
    int p, q, r;
};

int n, k;
int a[R + 1][N];
vector<st> ans;

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

void check() {
    for (int j = 1; j <= n; j++) {
        if (a[1][j] == a[2][j] && a[2][j] > 0) {
            ans.push_back({a[2][j], 1, j});
            a[2][j] = 0;
        }
        if (a[3][j] == a[4][j] && a[3][j] > 0) {
            ans.push_back({a[3][j], 4, j});
            a[3][j] = 0;
        }
    }
}

void rotate() {
    if (a[2][1] > 0 && a[3][1] == 0) {
        ans.push_back({a[2][1], 3, 1});
        swap(a[2][1], a[3][1]);
        return;
    }
    for (int j = 1; j < n; j++) {
        if (a[2][j] == 0 && a[2][j + 1] > 0) {
            ans.push_back({a[2][j + 1], 2, j});
            swap(a[2][j + 1], a[2][j]);
            return;
        }
    }
    for (int j = 2; j <= n; j++) {
        if (a[3][j] == 0 && a[3][j - 1] > 0) {
            ans.push_back({a[3][j - 1], 3, j});
            swap(a[3][j - 1], a[3][j]);
            return;
        }
    }
    if (a[3][n] > 0 && a[2][n] == 0) {
        ans.push_back({a[3][n], 2, n});
        swap(a[2][n], a[3][n]);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int it = 1; it <= 20000 - k; it++) {
        check();
        rotate();
    }
    for (int i = 1; i <= n; i++) {
        if (a[2][i] > 0 || a[3][i] > 0) dismiss();
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.p << " " << e.q << " " << e.r << '\n';
    }

    return 0;
}