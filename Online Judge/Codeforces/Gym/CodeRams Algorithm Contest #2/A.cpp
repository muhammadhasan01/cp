#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const string CODERAMS = "coderams";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string str;
    cin >> str;
    map<char, int> mp;
    for (char cc : str) {
        mp[cc]++;
    }
    int cnt = INF;
    for (char cc : CODERAMS) {
        cnt = min(cnt, mp[cc]);
    }
    cout << cnt << '\n';

    return 0;
}