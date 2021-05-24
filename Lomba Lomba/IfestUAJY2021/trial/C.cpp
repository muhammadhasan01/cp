#include<bits/stdc++.h>
using namespace std;

void solve() {
    vector<long long> ar;
    long long x;
    while (cin >> x) { ar.push_back(x); }
    long long n = (long long) ar.size();
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < i; j++) {
            for (long long k = 0; k < j; k++) {
                if (ar[j] == ar[i] + ar[k]) {
                    cout << ar[k] << ' ' << ar[j] << ' ' << ar[i] << '\n';
                }
            }
        }
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < i; j++) {
            for (long long k = 0; k < j; k++) {
                if (ar[i] == ar[j] + ar[k]) {
                    cout << ar[k] << ' ' << ar[j] << ' ' << ar[i] << '\n';
                }
            }
        }
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < i; j++) {
            for (long long k = 0; k < j; k++) {
                if (ar[k] == ar[i] + ar[j]) {
                    cout << ar[k] << ' ' << ar[j] << ' ' << ar[i] << '\n';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
  
    return 0;
}