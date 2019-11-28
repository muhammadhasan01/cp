#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n;
int a[N], pos[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[i] = 0;
        }
        int dif = n + 1;
        for (int i = 1; i <= n; i++) {
            if (pos[a[i]] == 0) {
                pos[a[i]] = i;
            } else {
                dif = min(dif, i - pos[a[i]] + 1);
                pos[a[i]] = i;
            }
        }
        cout << (dif == n + 1 ? -1 : dif) << '\n';
    }

    return 0;
}
