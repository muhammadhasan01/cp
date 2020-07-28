#include <bits/stdc++.h>

using namespace std;

const int N = 10;

char a[N + 5][N + 5];

bool check(int x, int y) {
    int c1 = 0, c2 = 0;
    for (int i = x; i <= min(N, x + 4); i++) {
        if (a[i][y] == 'X') ++c1;
        else if (a[i][y] == '.') ++c2;
    }
    if (c1 == 4 && c2 == 1) return true;
    c1 = c2 = 0;
    for (int j = y; j <= min(N, y + 4); j++) {
        if (a[x][j] == 'X') ++c1;
        else if (a[x][j] == '.') ++c2;
    }
    if (c1 == 4 && c2 == 1) return true;
    c1 = c2 = 0;
    for (int j = y; j <= min(N, y + 4); j++) {
        int dif = j - y;
        if (x - dif < 1) break;
        if (a[x - dif][j] == 'X') ++c1;
        else if (a[x - dif][j] == '.') ++c2;
    }
    if (c1 == 4 && c2 == 1) return true;
    c1 = c2 = 0;
    for (int i = x; i <= min(N, x + 4); i++) {
        int dif = i - x;
        if (y + dif > N) break;
        if (a[i][y + dif] == 'X') ++c1;
        else if (a[i][y + dif] == '.') ++c2;
    }
    if (c1 == 4 && c2 == 1) return true;
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (check(i, j)) {
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    cout << "NO" << '\n';

    return 0;
}