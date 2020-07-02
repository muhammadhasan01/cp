#include <bits/stdc++.h>

using namespace std;

long long k;
string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> s;
    int sum = 0;
    for (auto& e : s) {
        int x = (e - '0');
        sum += x;
    }
    if (sum >= k) {
        cout << 0 << '\n';
        return 0;
    }
    sort(s.begin(), s.end());
    int ans = 0;
    for (auto& e : s) {
        int dif = ('9' - e);
        sum += dif;
        ++ans;
        if (sum >= k) {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}