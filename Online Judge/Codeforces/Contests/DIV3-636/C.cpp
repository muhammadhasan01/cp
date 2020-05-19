#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, a[N];
bool sign[N];
long long ans;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sign[i] = (a[i] > 0);
        }
        ans = a[1];
        int curval = a[1];
        bool cursign = sign[1];
        for (int i = 2; i <= n; i++) {
            if (sign[i] == cursign) {
                if (a[i] > curval) {
                    ans += (1LL) * (a[i] - curval);
                    curval = a[i];
                }
            } else {
                ans += (1LL) * a[i];
                curval = a[i];
                cursign = !(cursign);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}