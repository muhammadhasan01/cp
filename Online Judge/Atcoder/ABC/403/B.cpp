#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string T, U;
    cin >> T >> U;
    int n = T.size();
    int m = U.size();
    for (int i = 0; i + m <= n; i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (T[i + j] != '?' && T[i + j] != U[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    
    return 0;
}