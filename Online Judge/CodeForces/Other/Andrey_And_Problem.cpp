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
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        double cur = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) cur *= p[j];
            else cur *= (1 - p[j]);
        }
        ans += cur;
    }
    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}
