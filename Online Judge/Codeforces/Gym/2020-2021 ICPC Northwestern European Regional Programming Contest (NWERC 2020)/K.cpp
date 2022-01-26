#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, t;
    getline(cin, s);
    getline(cin, t);
    map<char, int> cnt;
    for (char cc : s) {
        cnt[cc]++;
    }
    for (char cc : t) {
        cnt[cc]--;
    }
    for (auto [cc, cur] : cnt) {
        if (cur < 0) {
            cout << cc;
        }
    }
    cout << '\n';
    
    return 0;
}