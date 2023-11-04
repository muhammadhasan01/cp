#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> st;
    do {
        st.emplace(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << (int) st.size() << '\n';

    return 0;
}