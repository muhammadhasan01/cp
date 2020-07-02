#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) continue;
            bool flag = false;
            for (int row = 1; row <= n; row++) {
                for (int col = 1; col <= n; col++) {
                    if (a[row][j] + a[i][col] == a[i][j]) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (!flag) {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';

    return 0;
}