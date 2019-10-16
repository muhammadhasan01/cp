#include <bits/stdc++.h>
using namespace std;

int x[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x[0] >> x[1] >> x[2] >> x[3];
    for (int i = 0; i < 16; i++) {
        int res = 0;
        for (int j = 0; j < 4; j++) {
            bool b = (i & (1 << j));
            if (b) res += x[j];
            else res -= x[j];
        }
        if (res == 0) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}
