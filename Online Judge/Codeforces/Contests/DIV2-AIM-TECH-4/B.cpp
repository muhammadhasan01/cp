#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, m;
int a[N][N];
long long ans = 0;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<int> cnt(2);
        for (int j = 1; j <= m; j++) {
            cnt[a[i][j]]++;
        }
        for (int j = 0; j < 2; j++) {
            ans += (1LL << (cnt[j])) - 1LL;
        }
    }
    for (int j = 1; j <= m; j++) {
        vector<int> cnt(2);
        for (int i = 1; i <= n; i++) {
            cnt[a[i][j]]++;
        }
        for (int j = 0; j < 2; j++) {
            ans += (1LL << (cnt[j])) - 1LL;
        }
    }
    ans -= n * m;
    cout << ans << '\n';

    return 0;
}