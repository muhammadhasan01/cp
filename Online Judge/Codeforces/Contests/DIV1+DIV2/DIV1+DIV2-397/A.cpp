#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string home;
    cin >> home;
    vector<pair<string, string>> v(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        string dep = str.substr(0, 3);
        string arr = str.substr(5);
        v[i] = make_pair(dep, arr);
    }
    vector<bool> done(n);
    for (int i = 0; i < n; i++) {
        auto [dep_i, arr_i] = v[i];
        if (dep_i == home) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (j == i || done[j]) {
                    continue;
                }
                auto [dep_j, arr_j] = v[j];
                if (arr_j == home && dep_j == arr_i) {
                    done[j] = true;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "contest" << '\n';
                return 0;
            }
        }
    }
    cout << "home" << '\n';
    
    return 0;
}