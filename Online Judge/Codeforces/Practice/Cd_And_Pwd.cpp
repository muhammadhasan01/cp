#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    deque<string> ans;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "pwd") {
            for (int i = 0; i < (int) ans.size(); i++) {
                cout << "/" << ans[i];
            }
            cout << "/\n";
        } else {
            cin >> s;
            s += '/';
            if (s[0] == '/') while(!ans.empty()) ans.pop_back();
            string k = "";
            for (int i = 0; i < (int) s.size(); i++) {
                if (s[i] != '/') {
                    k += s[i];
                } else if ((int) k.size() > 0) {
                    if (k == "..") {
                        if ((int) ans.size() > 0) ans.pop_back();
                    } else {
                        ans.push_back(k);
                    }
                    k = "";
                }
            }
        }
    }

    return 0;
}
