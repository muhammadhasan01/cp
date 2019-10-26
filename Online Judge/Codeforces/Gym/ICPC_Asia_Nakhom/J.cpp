#include <bits/stdc++.h>
// https://www.qingtingip.com/h_241110.html
using namespace std;
#define double long double

const double eps = 1e-15;
const double mi = 1.0 / 3.0;
double sum = 0;
int x, y;

void pri(int p) {
    char s[10];
    int cc = 0;
    s[1] = s[2] = s[3] = 48;
    while (p > 0) {
        s[++cc] = 48 + (p % 10);
        p /= 10;
    }
    for (int i = 3; i >= 1; i--) cout << s[i];
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        sum = 0;
        for (int i = x; i <= y; i++) {
            double p1 = (double) i + eps;
            double p2 = (double) i;
            double tmp = 3.0 * pow(p1 * p2, mi);
            sum += (double) 1.0 / tmp;
        }
        int cnt = 15;
        while (sum + eps < 1) {
            cnt++;
            sum *= 10.0;
        }
        while (sum >= 10 + eps) {
            cnt--;
            sum /= 10.0;
        }
        cout << fixed << setprecision(5) << sum << "E-";
        pri(cnt);
    }

    return 0;
}
