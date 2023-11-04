#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k;
    cin >> k;
    vector<string> s(2);
    for (int i = 0; i < 2; i++) {
        cin >> s[i];
    }

    auto get = [&](string x) -> long long {
        long long ret = 0;
        reverse(x.begin(), x.end());
        long long cur = 1;
        for (char cc : x) {
            int num = cc - '0';
            ret += 1LL * num * cur;
            cur *= k;
        }
        return ret;
    };

    cout << get(s[0]) *  get(s[1]) << '\n';
    
    return 0;
}