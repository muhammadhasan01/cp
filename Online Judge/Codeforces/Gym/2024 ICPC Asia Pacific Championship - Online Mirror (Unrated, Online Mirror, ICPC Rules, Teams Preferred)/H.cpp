#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<bool> dominate(2);
    vector<int> one(n), zero(n);
    for (int i = 0; i < n; i++) {
        for (char cc : s[i]) {
            if (cc == '1') {
                one[i]++;
            } else {
                zero[i]++;
            }
        }
        if (one[i] == zero[i]) {
            dominate[0] = true;
            dominate[1] = true;
        } else if (one[i] > zero[i]) {
            dominate[1] = true;
        } else {
            dominate[0] = true;
        }
    }
    if (dominate[0] && dominate[1]) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(one[i], zero[i]);
        }
        cout << ans << '\n';
        return 0;
    }
    if (dominate[1]) {
        for (int i = 0; i < n; i++) {
            swap(one[i], zero[i]);
        }
    }
    int ones = accumulate(one.begin(), one.end(), 0);
    if (ones == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cur = ones - one[i] + zero[i];
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    
    return 0;
}