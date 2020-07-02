#include <bits/stdc++.h>

using namespace std;

const int INF = 1e4 + 5;
int k;

int F(int x) {
    return x * (x + 1) / 2;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for (int it = 0; it < 26; it++) {
        int l = 0, r = INF, pos = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (F(mid) <= k) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        k -= F(pos);
        char alf = char(int('a') + it);
        for (int i = 0; i <= pos; i++) cout << alf;
        if (k == 0) break;
    }
    cout << '\n';

    return 0;
}