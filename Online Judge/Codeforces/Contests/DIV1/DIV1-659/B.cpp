#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 30;

int tc;
int n, a[N];
int cnt[K + 5];

void solve() {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = K; j >= 0; j--) {
            bool b = (a[i] & (1 << j));
            if (b) {
                cnt[j]++;
            }
        }
    }
    for (int i = K; i >= 0; i--) {
        if (cnt[i]) {
            if (cnt[i] % 2 == 0) {
                continue;
            } else {
                if (cnt[i] % 4 == 1) {
                    cout << "WIN" << '\n';
                } else {
                    int rem = n - cnt[i];
                    cout << (rem & 1 ? "WIN" : "LOSE") << '\n';
                }
            }
            return;
        }
    }
    cout << "DRAW" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--)
        solve();
    
    return 0;
}