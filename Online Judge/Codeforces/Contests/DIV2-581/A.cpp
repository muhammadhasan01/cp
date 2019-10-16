#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {

            if (i < n - 1) {
                cnt++;
                continue;
            }

            bool ok = false;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '1') {
                    ok = true;
                    break;
                }
            }
            if (ok) cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}
