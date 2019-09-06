#include <bits/stdc++.h>
using namespace std;

const int N = 150 * 1000 + 5;
int n;
long long a[N], b[N];
long long g = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        g = __gcd(g, a[i] * b[i]);
    }
    if (g == 1) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        g = max(__gcd(g, a[i]), __gcd(g, b[i]));
    }
    cout << g << '\n';

    return 0;
}
