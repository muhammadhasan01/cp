#include <bits/stdc++.h>

using namespace std;

const int N = 65;
int tc;
int r, c;
char a[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> r >> c;
        bool flag = true;
        bool galf = true;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'A') {
                    flag = false;
                }
                if (a[i][j] == 'P') {
                    galf = false;
                }
            }
        }
        if (flag) {
            cout << "MORTAL" << '\n';
            continue;
        }
        if (galf) {
            cout << 0 << '\n';
            continue;
        }
        flag = false;
        int cnt = 0, cnt2 = 0;
        for (int i = 1; i <= c; i++) {
            if (a[1][i] == 'A') cnt++;
            if (a[r][i] == 'A') cnt2++;
        }
        if (cnt == c || cnt2 == c) {
            flag = true;
        }
        cnt = 0, cnt2 = 0;
        for (int i = 1; i <= r; i++) {
            if (a[i][1] == 'A') cnt++;
            if (a[i][c] == 'A') cnt2++;
        }
        if (cnt == r || cnt2 == r) {
            flag = true;
        }
        if (flag) {
            cout << 1 << '\n';
            continue;
        }
        for (int i = 2; i <= r - 1; i++) {
            cnt = 0;
            for (int j = 1; j <= c; j++) {
                if (a[i][j] == 'A') cnt++;
            }
            if (cnt == c) {
                flag = true;
                break;
            }
        }
        for (int j = 2; j <= c - 1; j++) {
            cnt = 0;
            for (int i = 1; i <= r; i++) {
                if (a[i][j] == 'A') cnt++;
            }
            if (cnt == r) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << 2 << '\n';
            continue;
        }
        if (a[1][1] == 'A' || a[1][c] == 'A' || a[r][1] == 'A' || a[r][c] == 'A') {
            cout << 2 << '\n';
            continue;
        }
        for (int i = 2; i <= r - 1; i++) {
            if (a[i][1] == 'A') flag = true;
            if (a[i][c] == 'A') flag = true;
        }
        for (int i = 2; i <= c - 1; i++) {
            if (a[1][i] == 'A') flag = true;
            if (a[r][i] == 'A') flag = true;
        }
        if (flag) {
            cout << 3 << '\n';
        } else {
            cout << 4 << '\n';
        }
    }

    return 0;
}
