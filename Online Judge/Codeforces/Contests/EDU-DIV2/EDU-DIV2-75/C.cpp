#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int tc;
char odd[N], even[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int n = s.length();
        int k1 = 0, k2 = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            if (c & 1) {
                odd[k1++] = s[i];
            } else {
                even[k2++] = s[i];
            }
        }
        int i = 0, j = 0, k = 0;
        while (1) {
            if (i == k1) {
                ans[++k] = even[j++];
            } else if (j == k2) {
                ans[++k] = odd[i++];
            } else {
                if (even[j] > odd[i]) {
                    ans[++k] = odd[i++];
                } else {
                    ans[++k] = even[j++];
                }
            }

            if (i == k1 && j == k2) break;
        }
        for (int i = 1; i <= k; i++) cout << ans[i];
        cout << '\n';
    }

    return 0;
}
