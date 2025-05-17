#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = (int) s.length();
    vector<pair<int, int>> p(n);
    for (int i = 0, pre = 0; i < n; i++) {
        p[i] = {pre, -i};
        if (s[i] == '(') {
            pre++;
        } else {
            pre--;
        }
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        int j = -p[i].second;
        cout << s[j];
    }
    cout << '\n';
    
    return 0;
}