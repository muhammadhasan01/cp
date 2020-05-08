#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n;
int a[N];
int ans;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) ans++;
    }
    cout << ans << '\n';

    return 0;
}