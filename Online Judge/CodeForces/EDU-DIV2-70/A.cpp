#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int tc;
string a, b;
int pl[N], lp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int last = 0;
        for (int i = 0; i < m; i++) {
            if (b[i] == '1') {
                last = i;
            }
        }
        last = m - last;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                int cur = n - i;
                if (cur >= last) {
                    ans = cur - last;
                }
            }
        }
        cout << ans << '\n';
    }


    return 0;
}
