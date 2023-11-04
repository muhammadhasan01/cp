#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m, a, b;
    cin >> m >> a >> b;
    int mini = 0;
    if ((a & 1) && (b & 1) && a + b == 2 * m) {
        mini = 1;
    }
    int maxi = min(a, b);
    cout << mini << ' ' << maxi << '\n';
    
    return 0;
}