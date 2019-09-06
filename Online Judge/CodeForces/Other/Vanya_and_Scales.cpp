#include <bits/stdc++.h>
using namespace std;

int w, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> m;
    if (m == 1 || w == 2) {
        puts("YES");
        return 0;
    }
    while (m > 0) {
        if (m % w == 0) {
            m /= w;
        } else if ((m + 1) % w == 0) {
            m = (m + 1) / w;
        } else if ((m - 1) % w == 0) {
            m = (m - 1) / w;
        } else {
            break;
        }
    }
    puts(m == 0 ? "YES" : "NO");

    return 0;
}
