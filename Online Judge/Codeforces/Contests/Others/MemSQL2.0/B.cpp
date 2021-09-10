#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n, m;
    cin >> n >> m;
    auto get_dist = [&](pair<long long, long long> p, pair<long long, long long> q) -> long double {
        auto [x1, y1] = p;
        auto [x2, y2] = q;
        return sqrtl(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
    };
    cout << 0 << ' ' << 0 << '\n';
    cout << n << ' ' << m << '\n';
    if (n > 0 && m > 0) {
        long double fst = get_dist(make_pair(n, m), make_pair(0, 1)) + get_dist(make_pair(0, 1), make_pair(n, m - 1));
        long double snd = get_dist(make_pair(n, m), make_pair(1, 0)) + get_dist(make_pair(1, 0), make_pair(n - 1, m));
        if (fst > snd) {
            cout << 0 << ' ' << 1 << '\n';
            cout << n << ' ' << m - 1 << '\n';
        } else {
            cout << 1 << ' ' << 0 << '\n';
            cout << n - 1 << ' ' << m << '\n';
        }
    } else if (n == 0) {
        cout << 0 << ' ' << 1 << '\n';
        cout << 0 << ' ' << m - 1 << '\n';
    } else if (m == 0) {
        cout << 1 << ' ' << 0 << '\n';
        cout << n - 1 << ' ' << 0 << '\n';
    }
    
    return 0;
}