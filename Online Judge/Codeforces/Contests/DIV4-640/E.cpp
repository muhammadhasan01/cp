#include <bits/stdc++.h>

using namespace std;

const int N = 8e3 + 5;
const int M = N * N;

int tc;
int n;
int a[N];
int pre[N], suf[N];
bitset<M> bitz;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            pre[i] = a[i] + pre[i - 1];
        }
        bitz.reset();
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                bitz[pre[j] - pre[i - 1]] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (bitz[a[i]]) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}