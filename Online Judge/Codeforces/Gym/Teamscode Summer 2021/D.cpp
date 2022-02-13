#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res(3);
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
        cnt[(int) (s[i] - 'A')]++;
        int max_cnt = *max_element(cnt.begin(), cnt.end());
        for (int it = 0; it < 3; it++) {
            if (cnt[it] == max_cnt) {
                res[it]++;
            }
        }
    }
    cout << *max_element(res.begin(), res.end()) << '\n';
    
    return 0;
}