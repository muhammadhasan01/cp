#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n;
int smallest_prime[N];
int I[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (smallest_prime[i] == 0) {
            for (int j = i; j <= n; j += i) {
                if (smallest_prime[j] == 0)
                    smallest_prime[j] = i;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        I[i - 1] = i / smallest_prime[i];
    }
    sort(I + 1, I + n);
    for (int i = 1; i < n; i++) {
        cout << I[i] << (i == n - 1 ? '\n' : ' ');
    }


    return 0;
}