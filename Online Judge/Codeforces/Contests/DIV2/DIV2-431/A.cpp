#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n;
int a[N];
bool dp[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n & 1) {
        cout << (a[1] % 2 == 1 && a[n] % 2 == 1 ? "Yes" : "No") << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}