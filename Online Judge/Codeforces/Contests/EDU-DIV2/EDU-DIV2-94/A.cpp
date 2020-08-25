#include <bits/stdc++.h>

using namespace std;

const int N = 200;
const char CC[] = {'0', '1'};

int tc;
int n;
char a[N];

void solve() {
    cin >> n;
    int k = 2 * n - 1;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << a[n];
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}