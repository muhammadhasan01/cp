#include<bits/stdc++.h>
using namespace std;

string s, t;

bool check(string a, string b) {
    bool ok = false;
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[j]) {
            j++;
            if (j == b.size()) {
                ok = true;
                break;
            }
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    int n = s.length();
    int m = s.length();
    int rlen = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int len = j - i + 1;
            string temp = s;
            temp.erase(temp.begin() + i, temp.begin() + j + 1);
            if (check(temp, t)) {
                rlen = max(rlen, len);
            }
        }
    }
    cout << rlen << '\n';

    return 0;
}
