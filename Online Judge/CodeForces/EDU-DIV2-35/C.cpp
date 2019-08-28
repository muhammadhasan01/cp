#include <bits/stdc++.h>
using namespace std;

int k[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k[0] >> k[1] >> k[2];
    sort(k, k + 3);
    if (k[0] == 1) {
        puts("YES");
    } else if (k[0] == 2 && k[1] == 2) {
        puts("YES");
    } else if (k[0] == 3 && k[1] == 3 && k[2] == 3) {
        puts("YES");
    } else if (k[0] == 2 && k[1] == 4 && k[2] == 4) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
