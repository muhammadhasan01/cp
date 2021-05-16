#include <bits/stdc++.h>

using namespace std;

const int N = 4;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int b = 0; b < (1 << N); b++) {
        vector<int> need(N);
        for (int i = 0; i < N; i++) {
            if (a[i] == n) {
                int j = (i == N - 1 ? 0 : i + 1);
                int k = (i == 0 ? N - 1 : i - 1);
                need[j]++, need[k]++;
            } else if (a[i] == n - 1) {
                int j = (i == N - 1 ? 0 : i + 1);
                int k = (i == 0 ? N - 1 : i - 1);
                if (b & (1 << i)) {
                    need[j]++;
                } else {
                    need[k]++;
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (a[i] < need[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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