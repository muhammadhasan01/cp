#include <bits/stdc++.h>

using namespace std;

const vector<int> primes = {2, 3, 5, 7};
const vector<int> not_primes = {1, 4, 6, 8, 9};
vector<vector<int>> pre;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        a[i] = cc - '0';
    }
    for (int num : not_primes) {
        for (int i = 0; i < n; i++) {
            if (a[i] == num) {
                cout << 1 << '\n';
                cout << num << '\n';
                return;
            }
        }
    }
    for (auto& v : pre) {
        for (int i = 0, j = 0; i < n; i++) {
            if (a[i] == v[j]) {
                j++;
                if (j == 2) {
                    cout << 2 << '\n';
                    cout << v[0] << v[1] << '\n';
                    return;
                }
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int x : primes) {
        for (int y : primes) {
            int z = 10 * x + y;
            bool not_prime = false;
            for (int i = 2; i * i <= z; i++) {
                if (z % i == 0) {
                    not_prime = true;
                    break;
                }
            }
            if (!not_prime) {
                continue;
            }
            pre.emplace_back(vector<int>{x, y});
        }
    }

    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}