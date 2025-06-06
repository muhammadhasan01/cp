#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, ans = 0, oc = 1;
string s;
int f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    stack<pair<char,int>> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' && st.empty()) {
            continue;
        } else if (s[i] == '(') {
            st.push({s[i], i});
        } else if (s[i] == ')' && st.top().first == '(') {
            int pos = st.top().second;
            f[i] = i - pos + 1;
            if (pos > 0 && f[pos - 1] > 0) f[i] += f[pos - 1];
            st.pop();
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] > ans) {
            ans = f[i];
            cnt = 1;
        } else if (f[i] == ans) {
            cnt++;
        }
    }

    if (ans > 0) oc = cnt;

    cout << ans << " " << oc << '\n';

    return 0;
}
