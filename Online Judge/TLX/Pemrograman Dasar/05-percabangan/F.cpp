#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    double n;
    cin >> n;
    int x = n;
    if (n == x) {
        cout << x << ' ' << x << '\n';
    } else if (n < 0) {
        cout << x - 1 << ' ' << x << '\n';
    } else {
        cout << x << ' ' << x + 1 << '\n';
    }
    
    return 0;
}