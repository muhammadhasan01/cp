#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n;
int w[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    n = 2 * n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    sort(w + 1, w + 1 + n);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cur = 0;
            int last = -1;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                if (last == -1) {
                    last = w[k];
                } else {
                    cur += (w[k] - last);
                    last = -1;
                }
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';

    return 0;
}