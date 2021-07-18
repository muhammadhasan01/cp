#include <bits/stdc++.h>

using namespace std;

const int K = 63;

long long two[K];

void solve() {
    int d;
    long long x;
    cin >> d >> x;
    if (x == 0) {
        cout << "YES " << 0 << '\n';
        return;
    }
    long long cur = 0;
    int max_turn = d + 1;
    for (int turn = 1; turn <= max_turn; turn++) {
        if (cur < x) {
            cur += two[d--];
        } else if (cur > x) {
            cur -= two[d--];
        }
        if (cur == x) {
            cout << "YES " << turn << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    two[0] = 1LL;
    for (int i = 1; i < K; i++) {
        two[i] = two[i - 1] + two[i - 1];
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case " << T << ": ";
        solve();
    }

    return 0;
}