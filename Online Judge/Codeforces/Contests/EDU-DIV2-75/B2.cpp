#include <bits/stdc++.h>

using namespace std;

int q;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        int od = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            int len = s.size();
            if (len & 1) od++;
            else {
                for (auto e : s) if (e == '1') cnt++;
            }
        }
        cout << (od || (cnt % 2 == 0) ? n : n - 1) << '\n';
    }

    return 0;
}
