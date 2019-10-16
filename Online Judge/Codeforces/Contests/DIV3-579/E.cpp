#include<bits/stdc++.h>
using namespace std;

const int N = 15 * 1000 * 10 + 5;
int n;
int a[N];
bitset<N> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1 && vis[a[i] - 1] == 0) {
            a[i]--;
            vis[a[i]] = 1;
            cnt++;
        } else if (a[i] == 1 && vis[a[i]] == 0) {
            vis[a[i]] = 1;
            cnt++;
        } else if (vis[a[i]] == 0) {
            vis[a[i]] = 1;
            cnt++;
        } else if(vis[a[i] + 1] == 0) {
            a[i]++;
            vis[a[i]] = 1;
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}
