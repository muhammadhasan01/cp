#include <bits/stdc++.h>

using namespace std;

const string playerOne = "DA";
const string playerTwo = "NET";

int tc;
string s;

void solve() {
    cin >> s;
    vector<char> st;
    int res = 0;
    for (auto& e : s) {
        if (st.empty()) {
            st.emplace_back(e);
        } else {
            if (st.back() != e) {
                st.pop_back();
                res++;
            } else {
                st.emplace_back(e);
            }
        }
    }
    cout << (res & 1 ? playerOne : playerTwo) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}