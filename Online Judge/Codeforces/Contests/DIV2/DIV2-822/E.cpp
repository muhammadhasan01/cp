#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<vector<int>> dif(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dif[i][j] = i;
        }
    }
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            if (j == 1) {
                a[i][j] = (a[i - 1][j] + dif[j][i - 1]) % n;
                continue;
            }
            if (i < n) {
                a[i][j] = (a[i][j - 1] + dif[i][j - 1]) % n;
                continue;
            }
            a[i][j] = (a[i - 1][j] + dif[j][i - 1]) % n;
        }
    }
    for (int i = 1; i <= n; i++) {
        int add = 0;
        while ((a[i][i] + add) % n != b[i]) add++;
        for (int j = 1; j <= n; j++) {
            cout << (a[i][j] + add) % n << " \n"[j == n];
        }
    }
    
    return 0;
}