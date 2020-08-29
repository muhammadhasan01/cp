#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e12 + 5;


int n;
long long a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int x = 1; (1LL << x) <= INF; x++) {
        long long cur = (1LL << x);
        map<long long, int> mp;
        for (int i = 1; i <= n; i++) {
            ans += (1LL) * mp[cur - a[i]];
            mp[a[i]]++;
        }
    }
    cout << ans << '\n';

    return 0;
}