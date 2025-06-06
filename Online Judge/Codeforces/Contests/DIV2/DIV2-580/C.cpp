#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long n;
long long ans[N];

void solve() {
    if (n % 2 == 0) {
        cout << "NO" << '\n';
        return;
    } else {
        long long pos = 1;
        for (int i = 1; i <= 2 * n; i++) {
            ans[pos] = i;
            if (i & 1) {
                pos += n;
            } else {
                pos++;
            }
            if (pos > 2 * n) pos -= 2 * n;
        }
        cout << "YES" << '\n';
        for (int i = 1; i <= 2 * n; i++) {
            cout << ans[i] << (i == 2 * n ? '\n' : ' ');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    solve();

    return 0;
}
