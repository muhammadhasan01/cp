#include <bits/stdc++.h>

using namespace std;

const int K = 5;

void solve() {
    vector<long long> a(K + 1);
    for (int i = 1; i <= K; i++) {
        cin >> a[i];
    }
    vector<long long> b(K + 1);
    for (int i = 1; i <= K; i++) {
        cin >> b[i];
    }

    auto take = [&](int i, int j) -> void {
        long long x = min(a[i], b[j]);
        a[i] -= x;
        b[j] -= x;
        b[j - i] += x;
    };

    take(5, 5);
    take(4, 4);
    take(4, 5);
    take(3, 3);
    take(3, 5);
    take(3, 4);
    for (int i = 0; i < K - 1; i++) {
        take(2, K - i);
    }
    for (int i = 0; i < K; i++) {
        take(1, K - i);
    }
    for (int i = 1; i <= K; i++) {
        if (a[i] > 0) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}