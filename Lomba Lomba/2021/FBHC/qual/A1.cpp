#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 26;
const vector<char> vowels = {'A', 'I', 'U', 'E', 'O'};
map<char, bool> is_vowel;

void solve() {
    string str;
    cin >> str;
    int ans = INF;
    for (int it = 0; it < K; it++) {
        char cur = char(it + int('A'));
        int res = 0;
        for (char cc : str) {
            if (cc == cur) {
                continue;
            }
            if (is_vowel.count(cur) == is_vowel.count(cc)) {
                res += 2;
            } else {
                res += 1;
            }
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (char cc : vowels) {
        is_vowel[cc] = true;
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}