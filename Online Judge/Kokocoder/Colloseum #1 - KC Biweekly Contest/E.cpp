#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            f[j]++;
        }
    }
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * i * f[i];
    }
    cout << ans << '\n';
    
    return 0;
}