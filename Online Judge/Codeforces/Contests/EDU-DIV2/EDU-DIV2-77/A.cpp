#include <bits/stdc++.h>

using namespace std;

int n;
long long c, sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c >> sum;
        long long k = sum / c, rem = sum % c;
        long long a = c - rem;
        cout << a * k * k + rem * (k + 1) * (k + 1) << '\n';
    }

    return 0;
}
