#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int n, m;
int res[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            bool b = (mask & (1 << i));
            if (!b) continue;
            sum += res[i];
        }
        if (sum == m) {
            puts("bisa");
            return 0;
        }
    }
    puts("tidak bisa");

    return 0;
}