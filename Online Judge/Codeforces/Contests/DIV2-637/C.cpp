#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int p[N], q[N];
bool vis[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            q[p[i]] = i;
            vis[i] = false;
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = q[i], cur = i; j <= n; j++, cur++) {
                if (vis[j]) break;
                if (cur != p[j]) {
                    flag = false;
                    break;
                }
                vis[j] = 1;
            }
            if (!flag) break;
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }

    return 0;
}