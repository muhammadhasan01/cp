#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int tc;
int n;
string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> s;
        int n = s.size();
        vector<bool> ok(10);
        cout << "Case #" << t << ": ";
        for (int i = 0; i < n; i++) {
            int num = (int) (s[i] - '0');
            if (!ok[num]) {
                for (int j = 1; j <= num; j++) cout << '(';
            }
            for (int j = 0; j < 10; j++) ok[j] = false;
            ok[num] = true;
            cout << s[i];
            if (i == n - 1 || (i + 1 < n && s[i + 1] != s[i])) {
                for (int j = 1; j <= num; j++) cout << ')';
            }
        }
        cout << '\n';
    }

    return 0;
}