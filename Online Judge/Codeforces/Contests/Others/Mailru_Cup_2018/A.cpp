#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int elevator = abs(x - z) * t2 + 2 * t3 + abs(x - y) * t2 + t3;
    int stairs = abs(x - y) * t1;
    cout << (elevator <= stairs ? "YES" : "NO") << '\n';
    
    return 0;
}