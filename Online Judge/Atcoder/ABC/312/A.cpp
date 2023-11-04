#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    set<string> st = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    string s;
    cin >> s;
    cout << (st.count(s) ? "Yes" : "No") << '\n';

    return 0;
}