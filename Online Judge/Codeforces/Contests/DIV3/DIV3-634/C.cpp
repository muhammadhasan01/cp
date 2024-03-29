#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
int a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int cur = 0;
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > cur) {
                cur = cnt[i];
                pos = i;
            }
        }
        int rem = 0;
        for (int i = 1; i <= n; i++) {
            if (i == pos) continue;
            if (cnt[i] > 0) {
                rem++;
            }   
        }
        cout << max(min(rem, cur), min(rem + 1, cur - 1)) << '\n';
    }

    return 0;
}