#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long sx, sy;
    cin >> sx >> sy;
    long long tx, ty;
    cin >> tx >> ty;
    long long dif = min(abs(sx - tx), abs(sy - ty));
    sx += (sx < tx ? dif : -dif);
    sy += (sy < ty ? dif : -dif);
    long long ans = dif;
    if (sx == tx) {
        ans += abs(sy - ty);
    } else if (sy == ty) {
        int add = (sy & 1 ? 1 : 0);
        sx = (sx + add) / 2;
        tx = (tx + add) / 2;
        ans += abs(sx - tx);
    }
    cout << ans << '\n';
    
    return 0;
}