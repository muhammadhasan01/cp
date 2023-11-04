#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<string> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    auto rotate = [&]() -> void {
        vector<string> rot = s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rot[i][j] = s[n - j - 1][i];
            }
        }
        s.swap(rot);
    };

    auto check = [&]() -> bool {
        vector<pair<int, int>> X, Y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '#') {
                    X.emplace_back(i, j);
                }
                if (t[i][j] == '#') {
                    Y.emplace_back(i, j);
                }
            }
        }
        if (X.size() != Y.size()) {
            return false;
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        int len = (int) X.size();
        int dx = X[0].first - Y[0].first;
        int dy = X[0].second - Y[0].second;
        for (int i = 1; i < len; i++) {
            int cdx = X[i].first - Y[i].first;
            int cdy = X[i].second - Y[i].second;
            if (dx != cdx || dy != cdy) {
                return false;
            }
        }
        return true;
    };

    for (int rep = 0; rep < 4; rep++) {
        if (check()) {
            cout << "Yes" << '\n';
            return 0;   
        }
        rotate();
    }
    cout << "No" << '\n';
    
    return 0;
}