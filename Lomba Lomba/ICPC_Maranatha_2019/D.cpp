#include <bits/stdc++.h>
using namespace std;

int n;
int k, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int t = 1; t <= n; t++) {
        cin >> b >> k;
        vector<vector<char>> a(k + 3, vector<char>(b + 3));
        vector<vector<int>> v(30, vector<int>(6, 0));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= b; j++) {
                cin >> a[i][j];
                int part;
                if (i <= k / 2 && j <= b / 2) {
                    part = 1;
                } else if (i <= k / 2 && j > b / 2) {
                    part = 2;
                } else if (i > k / 2 && j <= b / 2) {
                    part = 3;
                } else if (i > k / 2 && j > b / 2) {
                    part = 4;
                }
                v[a[i][j] - 'a'][part]++;
            }
        }
        vector<int> f(30, 0);
        for (int i = 0; i < 26; i++) {
            int maks = -1, part = -1;
            for (int j = 1; j <= 4; j++) {
                if (v[i][j] > maks) {
                    maks = v[i][j];
                    part = j;
                }
            }
            f[i] = part;
        }
        cout << t << '\n';
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= b; j++) {
                cout << a[i][j] << f[a[i][j] - 'a'] << (j == b ? '\n' : ' ');
            }
        }
    }

    return 0;
}
