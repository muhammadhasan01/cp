// author : m.hasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, k;
int ans, ansMax;
bitset<N> bitz;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        for (int j = x; j <= n; j += x) {
            if (bitz[j] == 0) {
                ans++;
                bitz[j] = 1;
            } else {
                ans--;
                bitz[j] = 0;
            }
        }
        ansMax = max(ans, ansMax);
    }
    cout << ansMax << '\n';

    return 0;
}