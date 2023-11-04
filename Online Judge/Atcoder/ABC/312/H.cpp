#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        vector<int> z = z_function(s[i]);
        int len = (int) z.size();
        int res = len;
        for (int j = 1; j < len; j++) {
            if (z[j] == len - j && len % j == 0) {
                res = j;
                break;
            }
        }
        mp[s[i].substr(0, res)].emplace_back(i);
    }
    vector<int> ans(n);
    for (auto& [str, v] : mp) {
        unordered_set<int> st = {0};
        unordered_map<int, int> last;
        int x = str.length();
        for (int i : v) {
            int y = s[i].length();
            assert(y % x == 0);
            int z = y / x;
            int cur = last[z];
            while (st.find(cur) != st.end()) {
                cur += z;
            }
            last[z] = cur;
            ans[i] = cur / z;
            st.emplace(cur);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
 
    return 0;
}