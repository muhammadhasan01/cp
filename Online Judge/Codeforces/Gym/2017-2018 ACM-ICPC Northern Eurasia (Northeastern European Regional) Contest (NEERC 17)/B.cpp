#include <bits/stdc++.h>

using namespace std;

int a, b, c, w, h;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> w >> h;
    if (w > h) swap(w, h);
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    do {
        int x = 2 * (v[0] + v[1]), y = 2 * v[1] + v[2];
        if (x > y) swap(x, y);
        if (w >= x && h >= y) {
            puts("Yes");
            return 0;
        }
        x = 3 * v[0] + v[1] + v[2], y = v[1] + v[2];
        swap(x, y);
        if (w >= x && h >= y) {
            puts("Yes");
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    puts("No");

    return 0;
}