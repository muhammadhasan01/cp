#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

long long res = 1;
string s, str;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    getline(cin, s);
    stringstream SS(s);
    while (SS >> str) {
        int n = str.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && str[i] == 'e' && str[i + 1] == 'u') {
                res = (3LL * res) % M;
                continue;
            } else if (str[i] == 'e') {
                res = (2LL * res) % M;
            }
        }
    }
    cout << (res % M + M) % M << "\n";

    return 0;
}