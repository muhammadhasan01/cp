#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n;
int a[2 * N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n = 2 * n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int m = n / 2;
    cout << (a[m + 1] > a[m] ? "YES" : "NO") << '\n';

    return 0;
}