#include <bits/stdc++.h>

using namespace std;

long long k;
string s = "codeforces";

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len = s.size();
    cin >> k;
    long long res = 1;
    long long x = 2;
    vector<int> f(len, 1);
    int ans = 1;
    int cnt = 0;
    while (res < k) {
        f[cnt]++;
        res = 1;
        for (int i = 0; i < len; i++) {
            res *= f[i];
        }
        if (++cnt == len) {
            cnt = 0;
            ++x;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < f[i]; j++) {
            cout << s[i];
        }
    }
    cout << '\n';
    
    return 0;
}