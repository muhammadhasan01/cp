#include <bits/stdc++.h>

using namespace std;

vector<int> LPS(string& s) {
    int n = (int) s.length();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

int KMPSearch(string& txt, string& pat) {
    int n = (int) txt.size();
    int m = (int) pat.size();
    vector<int> lps = LPS(pat);
    int cnt = 0;
    for (int i = 0, j = 0; i < n; ) {
        if (pat[j] == txt[i]) {
            i++, j++;
        }
        if (j == m) {
            ++cnt;
            j = lps[j - 1];
        } else if (pat[j] != txt[i]) {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string text = "13453457293045345";
    string pat = "45345";
    cout << KMPSearch(text, pat) << '\n';

    return 0;
}
