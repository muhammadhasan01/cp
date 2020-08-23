#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> last(26, -1);
    for (int i = 0; i < n; i++) {
        last[(int) (s[i] - 'a')] = i;
    }
    string res = "";
    stack<char> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty()) {
            char x = st.top();
            int cur = x - 'a';
            bool ok = true;
            for (int j = cur - 1; j >= 0; j--) {
                if (last[j] >= i) {
                    ok = false;
                }
            }
            if (ok) {
                res += x;
                st.pop();
            } else {
                break;
            }
        }
        st.emplace(s[i]);
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res << '\n';
    
    return 0;
}