#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
int n, k;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (k % x == 0) {
            ans = min(ans, k / x);
        }
    }
    cout << ans << '\n';


    return 0;
}
