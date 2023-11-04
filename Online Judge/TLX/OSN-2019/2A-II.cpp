#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> s(n), e(n);
    vector<int> S(n), E(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
        S[i] = s[i];
        E[i] = e[i];
    }
    sort(S.begin(), S.end());
    sort(E.begin(), E.end());
    for (int i = 0; i < n; i++) {
        int cur = n;
        int posL = lower_bound(E.begin(), E.end(), s[i]) - E.begin() - 1;
        if (posL >= 0) {
            cur -= (posL + 1);
        }
        int posR = upper_bound(S.begin(), S.end(), e[i]) - S.begin();
        if (posR < n) {
            cur -= (n - posR);
        }
        cout << cur - 1 << '\n';
    }
    
    return 0;
}