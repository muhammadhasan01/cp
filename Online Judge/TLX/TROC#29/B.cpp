#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    vector<vector<int>> cnt(2, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x & 1][y & 1]++;
    }
    for (int x : {0, 1}) {
        for (int y : {0, 1}) {
            for (int p : {0, 1}) {
                for (int q : {0, 1}) {
                    if ((x + y + p + q) % 2 == 0) {
                        continue;
                    }
                    if (cnt[x][y] && cnt[p][q]) {
                        cout << "YES" << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << '\n';
    
    return 0;
}