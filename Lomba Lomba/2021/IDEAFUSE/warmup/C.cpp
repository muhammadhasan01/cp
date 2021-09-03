#include <bits/stdc++.h>

using namespace std;

const vector<string> VOWELS = {"a", "i", "u", "e", "o"};

void solve() {
    string str;
    cin >> str;
    int len = str.size();
    vector<string> v;
    for (int i = 0; i < len; i++) {
        if (i + 1 < len && str[i] == 'n' && str[i + 1] == 'g') {
            v.emplace_back(str.substr(i, 2));
            i++;
            continue;
        } 
        v.emplace_back(str.substr(i, 1));
    }
    int n = v.size();
    vector<bool> capitalize(n);
    vector<bool> is_vowel(n);
    for (int i = 0; i < n; i++) {
        for (string vow : VOWELS) {
            if (v[i] == vow) {
                is_vowel[i] = true;
                break;
            }
        }
        if (is_vowel[i]) {
            if (i > 0 && is_vowel[i - 1]) {
                capitalize[i] = capitalize[i - 1] = true;
            }
        } else {
            if (i > 0 && !is_vowel[i - 1]) {
                capitalize[i] = capitalize[i - 1] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        string s = v[i];
        if (capitalize[i]) {
            for (char& cc : s) {
                cc = toupper(cc);
            }
        }
        cout << s;
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case #" << T << ": ";
        solve();
    }
    
    return 0;
}