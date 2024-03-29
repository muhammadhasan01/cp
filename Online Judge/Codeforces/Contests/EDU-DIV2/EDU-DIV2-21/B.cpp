#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, k;
long double a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long double sum = 0;
    long double cnt = n - k + 1;
    for (int i = k; i <= n; i++) {
        sum += a[i] - a[i - k];
    }
    cout << fixed << setprecision(9) << sum / cnt << '\n';

    return 0;
}
