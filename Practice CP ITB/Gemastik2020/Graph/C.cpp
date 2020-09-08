#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> r(2), c(2);
    for (int i = 0; i < 2; i++)
        cin >> r[i] >> c[i];
    cout << (r[0] == r[1] || c[0] == c[1] ? 1 : 2) << ' ';
    int dr = abs(r[0] - r[1]);
    int dc = abs(c[0] - c[1]);
    if (abs(dr - dc) % 2 == 0) {
        cout << (dr == dc ? 1 : 2) << ' ';
    } else {
        cout << 0 << ' ';
    }
    cout << dr + dc - min(dr, dc) << '\n';

    return 0;
}