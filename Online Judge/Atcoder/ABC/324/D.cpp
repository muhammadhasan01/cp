#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ans = 0;
    for (long long i = 0; ; i++) {
        string ss = to_string(i * i);
        int len = (int) ss.size();
        if (len > n) {
            break;
        }
        string cur = string(n - len, '0') + ss;
        sort(cur.begin(), cur.end());
        if (s == cur) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}