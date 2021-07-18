#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool not_prime[N];
int cprime[N];
int ans[N];

void solve() {
    int x;
    cin >> x;
    int y = ans[x];
    int g = __gcd(x, y);
    cout << (y / g) << '/' << (x / g) << '\n'; 
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (not_prime[i] == 1) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            if (j > i) {
                not_prime[j] = 1;
            }
            int x = j;
            while (cprime[j] <= 2 && x % i == 0) {
                x /= i;
                cprime[j]++;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        ans[i] = ans[i - 1];
        if (cprime[i] <= 2) {
            ans[i]++;
        }
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case " << T << ": ";
        solve();
    }

    return 0;
}