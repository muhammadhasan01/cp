#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n, m;
char a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    if (n % 3 == 0) {
        vector<char> v = {'R', 'G', 'B'};
        sort(v.begin(), v.end());
        do {
            bool flag = true;
            for (int it = 1; it <= 3; it++) {
                int start = 1 + (it - 1) * (n / 3);
                for (int i = start; i <= start + n / 3 - 1; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (a[i][j] != v[it - 1]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) break;
            }
            if (flag) {
                cout << "YES" << '\n';
                return 0;
            }
        } while (next_permutation(v.begin(), v.end()));
    }
    if (m % 3 == 0) {
        vector<char> v = {'R', 'G', 'B'};
        sort(v.begin(), v.end());
        do {
            bool flag = true;
            for (int it = 1; it <= 3; it++) {
                int start = 1 + (it - 1) * (m / 3);
                for (int j = start; j <= start + m / 3 - 1; j++) {
                    for (int i = 1; i <= n; i++) {
                        if (a[i][j] != v[it - 1]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) break;
            }
            if (flag) {
                cout << "YES" << '\n';
                return 0;
            }
        } while (next_permutation(v.begin(), v.end()));
    }
    cout << "NO" << '\n';

    return 0;
}