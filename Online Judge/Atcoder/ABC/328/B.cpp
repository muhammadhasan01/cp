#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    auto getVector = [&](int x) -> vector<char> {
        string s = to_string(x);
        vector<char> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        return v;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<char> I = getVector(i);
        if ((int) I.size() > 1) {
            continue;
        }
        for (int dd = 1; dd <= d[i]; dd++) {
            vector<char> D = getVector(dd);
            if ((int) D.size() > 1) {
                continue;
            }
            if (I == D) {
                ++ans;
            } 
        }
    }
    cout << ans << '\n';
    
    return 0;
}