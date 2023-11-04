#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);

    auto F = [&](double k) -> double {
        double lft = 0;
        double l = 0;
        for (int i = 0; i < n; i++) {
            l += a[i];
            if (l >= k) {
                lft += (double) (a[i] - l + k) / b[i];
                break;
            }
            lft += (double) a[i] / b[i];
        }
        double rgt = 0;
        double r = sum;
        for (int i = n - 1; i >= 0; i--) {
            r -= a[i];
            if (r <= k) {
                rgt += (double) (a[i] + r - k) / b[i];
                break;
            }
            rgt += (double) a[i] / b[i];
        }
        return abs(lft - rgt);
    };

    double l = 0, r = sum;
    while (r - l > EPS) {
        double L = l + (r - l) / 3;
        double R = r - (r - l) / 3;
        if (F(L) > F(R)) {
            l = L;
        } else {
            r = R;
        }
    }
    cout << fixed << setprecision(9) << l << '\n';
    
    return 0;
}