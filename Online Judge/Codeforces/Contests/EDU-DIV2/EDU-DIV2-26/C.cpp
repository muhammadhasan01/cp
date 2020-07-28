#include <bits/stdc++.h>

using namespace std;
 
using namespace IO;

const int N = 1e2 + 5;

int n, a, b;
int l[N], r[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> a >> b;
    if (a > b) swap(a, b);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] > r[i]) swap(l[i], r[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int it = 0; it < 2; it++) {
                for (int kk = 0; kk < 2; kk++) {
                    if (l[i] + l[j] <= a && r[i] <= b && r[j] <= b) {
                        ans = max(ans, l[i] * r[i] + l[j] * r[j]);
                    }
                    if (r[i] + r[j] <= b && l[i] <= a && l[j] <= a) {
                        ans = max(ans, l[i] * r[i] + l[j] * r[j]);
                    }
                    swap(l[j], r[j]);
                }
                swap(l[i], r[i]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}