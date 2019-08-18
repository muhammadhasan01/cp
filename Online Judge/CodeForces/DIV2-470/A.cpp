#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int r, c;
char a[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == 'S') {
                for (int it = 0; it < 4; it++) {
                    int ri = i + dx[it];
                    int ry = j + dy[it];
                    if (ri > r || ri < 0) continue;
                    if (ry > c || ry < 0) continue;
                    if (a[ri][ry] == 'W') {
                        puts("No");
                        return 0;
                    } else if (a[ri][ry] != 'S'){
                        a[ri][ry] = 'D';
                    }
                }
            }
        }
    }

    cout << "Yes" << '\n';
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << a[i][j];
        }cout << '\n';
    }

    return 0;
}
