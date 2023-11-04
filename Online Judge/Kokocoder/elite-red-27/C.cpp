#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bitset<N> notPrime;
int ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 2; i < N; i++) {
        if (notPrime[i]) {
            continue;
        }
        for (int j = i + i; j < N; j += i) {
            notPrime[j] = 1;
        }
    }
    ans[1] = 1;
    for (int i = 2; i < N; i++) {
        if (notPrime[i]) {
            ans[i] += ans[i - 1];
        } else {
            ans[i] += ans[i - 1] + 1;
            long long j = 1LL * i * i;
            if (j < N) {
                ans[j]--;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
    
    return 0;
}