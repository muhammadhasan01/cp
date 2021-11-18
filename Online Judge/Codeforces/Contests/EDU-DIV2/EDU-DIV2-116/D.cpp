#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> ans(K);
    for (int c = 0; c < K; c++) {
        char cc = char(int('a') + c);
        for (int i = 0; i < n; i++) {
            if (s[i] == cc || t[i] == cc) {
                ans[c]++;
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    
    return 0;
}