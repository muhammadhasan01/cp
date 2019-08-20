#include<bits/stdc++.h>
using namespace std;

int n, l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    long long ansl = 0, ansr = 0;
    for (int i = 1; i <= n; i++) {
        if (i > l) {
            ansl++;
        } else {
            ansl += (1LL << (i - 1));
        }
        if (i > r) {
            ansr += (1LL << (r - 1));
        } else {
            ansr += (1LL << (i - 1));
        }
    }
    cout << ansl << " " << ansr << '\n';

    return 0;
}
