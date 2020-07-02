    #include <bits/stdc++.h>

    using namespace std;

    const int N = 55;

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
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
            }
            sort(a + 1, a + 1 + n);
            int ans = 2e9;
            for (int i = 1; i < n; i++) {
                ans = min(ans, a[i + 1] - a[i]);
            }
            cout << ans << '\n';
        }

        return 0;
    }