#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;
int q, n;
long long k;
long long pos[N];
char s[N];
bool vis[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n >> k;
        int len = 0;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            if (s[i] == '0') pos[++len] = i;
            vis[i] = 1;
        }
        for (int i = 1; i <= len; i++) {
            if (pos[i] - i <= k) {
                k -= (pos[i] - i);
                pos[i] = i;
            } else {
                pos[i] -= k;
                k = 0;
            }
            vis[pos[i]] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cout << vis[i];
        }
        cout << '\n';
    }


    return 0;
}
