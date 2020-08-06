#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n; i++) {
        if (a[i + 1] - a[i] >= 2) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--)
        solve();

    return 0;
}