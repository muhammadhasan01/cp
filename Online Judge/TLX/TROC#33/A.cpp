#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    const int total = 20 + 2 * 15;
    int sayed = (n - x) + 2 * (m - y);
    cout << (sayed * 2 > total ? "LOLOS" : "TIDAK LOLOS") << '\n';    
    
    return 0;
}