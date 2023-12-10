#include <bits/stdc++.h>

using namespace std;

const int K = 2;
const int A = 26;

void solve() {
    int n;
    cin >> n;
    vector<string> s(K);
    for (int i = 0; i < K; i++) {
        cin >> s[i];
    }
    vector<vector<int>> cnt(A, vector<int>(A));
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        int x = s[0][i] - 'a';
        int y = s[1][j] - 'a';
        if (x > y) {
            swap(x, y);
        }
        cnt[x][y]++;
    }
    int c = 0;
    for (int i = 0; i < A; i++) {
        for (int j = i; j < A; j++) {
            if (cnt[i][j] & 1) {
                ++c;
                if (i != j) {
                    ++c;
                }
            }
        }
    }
    cout << (c > 1 ? "NO" : "YES") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}