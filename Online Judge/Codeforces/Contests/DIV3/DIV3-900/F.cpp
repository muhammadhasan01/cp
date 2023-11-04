#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int p[N];

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    int D = 1;

    auto addPrime = [&](int prime) -> void {
        mp[prime]++;
        D = D + D / mp[prime];
    };

    auto addNumber = [&](int x) -> void {
        while (x > 1) {
            int pp = p[x];
            while (x % pp == 0) {
                x /= pp;
                addPrime(pp);
            }
        }
    };

    auto answerQuery = [&]() -> void {
        int cur = D;
        for (auto& [prime, cnt] : mp) {
            for (int i = 0; i < cnt; i++) {
                if (cur % prime != 0) {
                    break;
                }
                cur /= prime;
            }
        }
        cout << (cur == 1 ? "YES" : "NO") << '\n';
    };

    auto reset = [&]() -> void {
        mp.clear();
        D = 1;
        addNumber(n);
    };

    reset();
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            addNumber(x);
            answerQuery();
        } else {
            reset();
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < N; i++) {
        if (p[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            p[j] = i;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}