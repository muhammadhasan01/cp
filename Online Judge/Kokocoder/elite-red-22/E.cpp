#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        double a;
        cin >> a;
        int ai = a;
        if (a - ai == 0) {
            ++cnt;
        }
        sum += a - ai;
    }
    double res = n - sum;
    double ans = LLONG_MAX;
    for (int take = 0; take <= min(cnt, n); take++) {
        double cur = res - take;
        ans = min(ans, fabs(cur));
    }
    cout << fixed << setprecision(3) << ans << '\n';
    
    return 0;
}