#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
double p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + 1 + n, greater<double>());
    double ans = -1, cur = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        cur *= (1 - p[i]);
        if (p[i] == 1.0) {
            cout << p[i] << '\n';
            return 0;
        }
        sum += p[i] / (1 - p[i]);
        ans = max(ans, cur * sum);
    }
    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}
