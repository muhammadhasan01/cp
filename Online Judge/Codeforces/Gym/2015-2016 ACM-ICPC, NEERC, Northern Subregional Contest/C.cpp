#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

string s, t;
int val[30];
int n, m;
long long res;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("concatenation.in", "r", stdin);
    freopen("concatenation.out", "w", stdout);
    cin >> s >> t;
    n = s.length(), m = t.length();
    for (int i = 0; i < m - 1; i++) {
        val[(int) (t[i] - 'a')]++;
    }
    for (int i = 0; i < n; i++) {
        res += (1LL) * m;
        if (i) res -= (1LL) * val[(int) (s[i] - 'a')];
    }
    cout << res << '\n';

    return 0;
}