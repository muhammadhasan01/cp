#include <bits/stdc++.h>

using namespace std;

int main () {
    srand(time(NULL));
    ofstream f;
    f.open("accountz.csv");
    string s;
    f << "accounts 1" << '\n';
    int cur = 65;
    while (cin >> s) {
        f << "team" << '\t' << s << ' ' << "teamCP_" << cur << '\n';
        cur++; 
    }
    f.close();
    return 0;
}