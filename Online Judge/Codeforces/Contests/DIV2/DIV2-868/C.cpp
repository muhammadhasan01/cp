#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int pp[N];

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int p = pp[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                ++cnt;
            }
            mp[p] += cnt;
        }
    }
    long long res = 0;
    long long rem = 0;
    for (auto [d, cnt] : mp) {
        res += cnt / 2;
        rem += (cnt & 1);
    }
    res += rem / 3;
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (pp[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            pp[j] = i;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}