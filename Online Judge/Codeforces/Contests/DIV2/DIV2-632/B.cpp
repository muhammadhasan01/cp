#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int a[N], b[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<bool> one(n + 1);
        vector<bool> mone(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            one[i] = one[i - 1];
            mone[i] = mone[i - 1];
            if (a[i] > 0) {
                one[i] = true;
            } else if (a[i] < 0) {
                mone[i] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        bool flag = true;
        for (int i = n; i >= 1; i--) {
            if (a[i] > b[i]) {
                if (mone[i - 1]) continue;
                flag = false;
                break;
            } else if (a[i] < b[i]) {
                if (one[i - 1]) continue;
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}