#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int tc;
char a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1, j = 1; i <= 9; i++, j += 3) {
            if (i % 3 == 1) j = i / 3 + 1;
            if (a[i][j] == '9') {
                a[i][j] = '1';
            } else {
                a[i][j]++;
            }
        }
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}