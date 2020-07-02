#include <bits/stdc++.h>

using namespace std;

int tc, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s;
        vector<int> ans;
        n = s.length();
        for (int i = 0; i <= n - 5; i++) {
            if (s.substr(i, 5) == "twone") {
                ans.push_back(i + 3);
            }
        }
        for (int i = 0; i <= n - 3; i++) {
            if (s.substr(i, 3) == "one") {
                if (i - 2 >= 0 && s.substr(i - 2, 2) == "tw") continue;
                ans.push_back(i + 2);
            }
        }
        for (int i = 0; i <= n - 3; i++) {
            if (s.substr(i, 3) == "two") {
                if (i + 4 < n && s.substr(i + 3, 2) == "ne") continue;
                ans.push_back(i + 2);
            }
        }
        cout << ans.size() << '\n';
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << '\n';
    }

    return 0;
}
