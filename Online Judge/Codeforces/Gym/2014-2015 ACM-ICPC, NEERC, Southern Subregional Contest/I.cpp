// author: mhasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n;
int p[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + 1 + n);
    int cur = p[n];
    int ans = 1;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (sum + p[i] <= cur) {
            ans++;
            sum += p[i];
        } else {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}