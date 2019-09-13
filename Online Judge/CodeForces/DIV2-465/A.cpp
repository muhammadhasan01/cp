#include <bits/stdc++.h>
using namespace std;

int n;

int solve(int k) {
    if (k == 2) return 1;
    int ret = 0;
    for (int i = 1; i <= k - 1; i++) {
        if (k % i == 0) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << solve(n) << '\n';

    return 0;
}
