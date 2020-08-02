#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

void solve() {
    cin >> n;
    string res(n, '9');
    for (int i = 0; i < (n + 3) / 4; i++)
        res[i] = '8';
    reverse(res.begin(), res.end());
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}