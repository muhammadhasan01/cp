#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        cout << -a[1] << '\n';
        for (int it = 0; it < 2; it++) {
            cout << 1 << ' ' << 1 << '\n';
            cout << 0 << '\n';
        }
        return 0;
    }
    long long m = n;
    cout << 1 << ' ' << 1 << '\n';
    cout << -a[1] << '\n';
    cout << 2 << ' ' << n << '\n';
    for (int i = 2; i <= n; i++) {
        long long b = n + a[i];
        cout << b * (m - 1) << (i == n ? '\n' : ' ');
    }
    cout << 1 << ' ' << n << '\n';
    for (int i = 1; i <= n; i++) {
        long long b = 1 - m - a[i];
        if (i == 1) {
            cout << 0 << ' ';
        } else {
            cout << m * b << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}