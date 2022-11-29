#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k;
    cin >> k;
    auto get_rotation = [&](string& s) -> string {
        string ret(4, '#');
        for (int i = 0; i < 4; i++) {
            int j = (i - 1);
            if (j < 0) {
                j += 4;
            }
            ret[i] = s[j];
        }
        return ret;
    };
    auto get_vector = [&](string& s) -> vector<string> {
        vector<string> v;
        for (int i = 0; i < 4; i++) {
            s = get_rotation(s);
            v.emplace_back(s);
        }
        sort(v.begin(), v.end());
        return v;
    };
    map<vector<string>, int> mp;
    for (int it = 0; it < k; it++) {
        string s(4, '#');
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> s[i + i + j];
            }
        }
        swap(s[2], s[3]);
        mp[get_vector(s)]++;
    }
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            string s(4, '#');
            s[0] = a[i][j];
            s[1] = a[i][j + 1];
            s[2] = a[i + 1][j + 1];
            s[3] = a[i + 1][j];
            vector<string> cur = get_vector(s);
            if (!mp.count(cur)) {
                cout << "No" << '\n';
                return 0;
            }
            if (--mp[cur] == 0) {
                mp.erase(cur);
            }
        }
    }
    cout << "Yes" << '\n';
    
    return 0;
}