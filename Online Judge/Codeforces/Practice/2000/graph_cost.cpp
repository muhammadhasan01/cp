#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int p[N];
long long pre[N];

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    long long cost = 0;
    for (int i = n; i >= 1; i--) {
        long long slot = pre[n / (i + 1)] / i;
        long long take = min(m / i, slot);
        m -= take * i;
        cost += 1LL * take * (i + 1);
    }
    if (m > 0) {
        cost = -1;
    }
    cout << cost << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 2; i < N; i++) {
        if (p[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            p[j] = i;
        }
    }
    for (int i = 2; i < N; i++) {
        pre[i] = pre[i - 1];
        int x = i;
        long long phi = x;
        while (x > 1) {
            int cur = p[x];
            phi /= cur;
            phi *= (cur - 1); 
            while (x % cur == 0) {
                x /= cur;
            }
        }
        pre[i] += phi;
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}