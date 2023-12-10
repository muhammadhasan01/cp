#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    int len = (int) t.size();
    while (s.find(t) != string::npos) {
        s.erase(s.find(t), len);
    }
    cout << s << '\n';
    
    return 0;
}