#include <bits/stdc++.h>

using namespace std;

const int CC[2] = {'r', 'b'};

char DP(long long pos, int it) {
    if (pos == 1) {
        return CC[it];
    }
    long long x = 1;
    while (x < pos) {
        x = x + x;
    }
    x /= 2;
    return DP(pos - x, 1 - it);
}

void solve() {
    long long n;
    cin >> n;
    cout << (DP(n, 0) == 'r' ? "Red" : "Blue") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}