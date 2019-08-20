#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = 200 * 100 + 5;
int n, m;
int a[N], b[N];
bitset<M> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        vis[b[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int res = a[i] + b[j];
            if (vis[res] == 0) {
                cout << a[i] << " " << b[j] << '\n';
                return 0;
            }
        }
    }


    return 0;
}
