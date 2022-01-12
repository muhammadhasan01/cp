#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long double n, x, y;
    cin >> n >> x >> y;
    cout << fixed << setprecision(9);
    cout << n << ' ';
    n = (n * 10000) / (10000 - (100 - x) * y);
    cout << n << ' ';
    n = (n * (100 - x)) / 100;
    cout << n << ' ';
    n = (n * (100 - y)) / 100;
    cout << n << ' ';
    cout << n << '\n';
    
    return 0;
}