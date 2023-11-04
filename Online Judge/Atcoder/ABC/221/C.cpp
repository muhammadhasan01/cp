#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    sort(s.begin(), s.end());
    long long ans = 0;
    do {
        for (int i = 0; i + 1 < n; i++) {
            string X = s.substr(0, i + 1);
            string Y = s.substr(i + 1);
            if ((int) X.size() > 1 && X[0] == '0') {
                continue;
            }
            if ((int) Y.size() > 1 && Y[0] == '0') {
                continue;
            }
            int x = stoi(X);
            int y = stoi(Y);
            ans = max(ans, 1LL * x * y);
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << '\n';
    
    return 0;
}