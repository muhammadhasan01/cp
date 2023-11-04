#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s;
        char last = s.back();
        s.pop_back();
        s = last + s;
    }
    sort(v.begin(), v.end());
    cout << v[0] << '\n';
    cout << v.back() << '\n';
    
    return 0;
}