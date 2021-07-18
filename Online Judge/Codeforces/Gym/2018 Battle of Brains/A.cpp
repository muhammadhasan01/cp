#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < 4; i++) {
        long long x;
        cin >> x;
        sum += x;
    }
    n += 1;
    cout << (sum * 2 >= n ? "Yes" : "No") << '\n';
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