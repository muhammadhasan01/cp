#include <bits/stdc++.h>

using namespace std;

const int K = 26;

bool good[K + 5];
string s;
int n, q;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string gg;
    cin >> gg;
    for (auto& e : gg) {
        good[(int) (e - 'a')] = true;
    }
    cin >> s;
    n = s.length();
    string ss = s;
    for (int i = 0; i < n; i++) {
        if (ss[i] == '*') {
            ss.erase(ss.begin() + i);
            break;
        }
    }
    int m = ss.length();
    cin >> q;
    string qr;
    while (q--) {
        cin >> qr;
        int len = qr.size();
        bool flag = true;
        if (len >= n) {
            int dif = len - n;
            for (int i = 0, j = 0; i < len; i++) {
                if (s[j] == '*') {
                    int alf = qr[i] - 'a';
                    if (good[alf]) {
                        flag = false;
                        break;
                    }
                    if (dif) {
                        --dif;
                    } else {
                        ++j;
                    }
                    continue;
                }
                if (s[j] == '?') {
                    int alf = qr[i] - 'a';
                    if (!good[alf]) {
                        flag = false;
                        break;
                    }
                } else if (s[j] != qr[i]) {
                    flag = false;
                    break;
                }
                ++j;
            }
        } else if (m == len) {
            for (int i = 0; i < len; i++) {
                if (ss[i] == '?') {
                    int alf = qr[i] - 'a';
                    if (!good[alf]) {
                        flag = false;
                        break;
                    }
                } else if (ss[i] != qr[i]) {
                    flag = false;
                    break;
                }
            }
        } else {
            flag = false;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}