#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;
    cout << (y % x == 0 ? "Yes" : "No") << '\n';

    return 0;
}