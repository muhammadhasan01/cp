#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    n = n + n;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> score(n);
    for (int j = 0; j <= m; j++) {
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int& x, int& y) {
            if (score[x] == score[y]) {
                return x < y;
            }
            return score[x] > score[y];
        });
        if (j == m) {
            for (int i = 0; i < n; i++) {
                cout << ord[i] + 1 << '\n';
            }
            return 0;
        }
        for (int i = 0; i + 1 < n; i += 2) {
            int l = ord[i];
            int r = ord[i + 1];
            if (a[l][j] != a[r][j]) {
                if (a[l][j] == 'G') {
                    score[l] += a[r][j] == 'C';
                    score[r] += a[r][j] == 'P';
                } else if (a[l][j] == 'C') {
                    score[l] += a[r][j] == 'P';
                    score[r] += a[r][j] == 'G';
                } else if (a[l][j] == 'P') {
                    score[l] += a[r][j] == 'G';
                    score[r] += a[r][j] == 'C';
                }
            }
        }
    }
    assert(false);
    
    return 0;
}