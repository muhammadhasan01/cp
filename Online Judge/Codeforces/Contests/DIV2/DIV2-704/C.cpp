#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> idf(m), idb(m);
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == t[j]) {
            idf[j] = i;
            j += 1;
            if (j == m) {
                break;
            }
        }
    }
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        if (s[i] == t[j]) {
            idb[j] = i;
            j -= 1;
            if (j < 0) {
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < m; i++) {
        ans = max(ans, idf[i] - idf[i - 1]);
        ans = max(ans, idb[i] - idb[i - 1]);
        ans = max(ans, idb[i] - idf[i - 1]);
    }
    cout << ans << '\n';
    
    return 0;
}