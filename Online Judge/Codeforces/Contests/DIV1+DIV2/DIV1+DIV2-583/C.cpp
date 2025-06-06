#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    if (n & 1) {
        puts("No");
        return 0;
    }

    stack<char> st;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(s[i]);
        } else if (st.top() == '(' && s[i] == ')') {
            st.pop();
        } else if (st.top() == ')' && !ok) {
            ok = true;
            st.pop();
            st.push(s[i]);
        } else {
            st.push(s[i]);
        }
    }

    if (st.empty()) {
        puts("Yes");
    } else if (ok && (int) st.size() == 1 && st.top() == '(') {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
