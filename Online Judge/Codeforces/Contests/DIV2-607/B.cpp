#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
int tc;
string s, t;
pair<char, int> suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s >> t;
        int la = s.length();
        suf[la - 1] = {s[la - 1], la - 1};
        for (int i = la - 2; i >= 0; i--) {
            if (suf[i + 1].first > s[i]) {
                suf[i] = {s[i], i};
            } else {
                suf[i] = suf[i + 1];
            }
        }
        for (int i = 0; i < la - 1; i++) {
            if (s[i] > suf[i + 1].first) {
                swap(s[i], s[suf[i + 1].second]);
                break;
            }
        }
        cout << (s < t ? s : "---") << '\n';
    }

    return 0;
}
