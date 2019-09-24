#include <bits/stdc++.h>
using namespace std;

double a1, b1, a2, b2, a3, b3;
const double eps = 1e-5;
const double pi = 3.1415926535897;

double dist(double a, double b, double c, double d) {
    return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

double get(double a, double b, double c) {
    return acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2.0 * a * b));
}

double gcd(double a, double b) {
    while (fabs(a) > eps && fabs(b) > eps) {
        if (a > b) {
            a -= floor(a / b) * b;
        } else {
            b -= floor(b / a) * a;
        }
    }
    return a + b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    double AB = dist(a1, b1, a2, b2);
    double BC = dist(a2, b2, a3, b3);
    double AC = dist(a1, b1, a3, b3);

    double A = get(AB, AC, BC);
    double B = get(AB, BC, AC);
    double C = get(AC, BC, AB);

    double R = (AB * BC * AC) / (2 * (AB * AC * sin(A)));

    double n = pi / gcd(A, gcd(B, C));

    double theta = (2 * pi) / n;

    double ans = (n / 2.0) * pow(R, 2) * sin(theta);

    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}
