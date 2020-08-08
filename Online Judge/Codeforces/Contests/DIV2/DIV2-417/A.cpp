#include <bits/stdc++.h>

using namespace std;

bool x[4][4];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> x[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        if (x[i][3]) {
            int j = i, k = 0;
            for (int it = 0; it < 3; it++) {
                j = (j + 1) % 4;
                if (x[j][k++] || x[i][it]) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");

    return 0;
}