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
    sort(a + 1, a + 1 + n);
    long long x = 0, y = 0;
    if (n & 1) {
        for (int i = 1; i <= n / 2; i++) {
            x += a[i];
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            y += a[i];
        }
        cout << x * x + y * y << '\n';
    } else {
        long long x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            if (i <= n / 2) x += a[i];
            else y += a[i];
        }
        cout << x * x + y * y << '\n';
    }

    return 0;
}
