#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h + 1, vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i1 = 1; i1 <= h; i1++) {
        for (int i2 = i1 + 1; i2 <= h; i2++) {
            for (int j1 = 1; j1 <= w; j1++) {
                for (int j2 = j1 + 1; j2 <= w; j2++) {
                    if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2]) {
                        cout << "No" << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << '\n';
    
    return 0;
}