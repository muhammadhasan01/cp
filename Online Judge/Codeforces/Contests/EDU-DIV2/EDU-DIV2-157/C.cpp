#include <bits/stdc++.h>

using namespace std;

const int K = 5;

map<string, map<int, int>> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    auto getMapFromString = [&](string& str) {
        if (mp.find(str) != mp.end()) {
            return mp[str];
        }
        int len = str.length();
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            if ((int) s[i].length() != len) {
                continue;
            }
            int value = 0;
            for (int j = 0; j < len; j++) {
                int num = s[i][j] - '0';
                value += (str[j] == '+' ? num : -num); 
            }
            freq[value]++;
        }
        mp[str] = freq;
        return mp[str];
    };

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int len = s[i].length();
        for (int j = (len & 1 ? 1 : 2); j <= K; j += 2) {
            string cur(len + j, '+');
            int m = cur.size();
            for (int x = 0; x < m / 2; x++) {
                cur[x] = '-';
            }
            string other(j, '#');
            for (int x = len; x < m; x++) {
                other[x - len] = cur[x];
            }
            map<int, int> freq = getMapFromString(other);
            int val = 0;
            for (int x = 0; x < len; x++) {
                int num = s[i][x] - '0';
                val += (cur[x] == '-' ? num : -num); 
            }
            ans += freq[val];
        }
    }
    cout << ans << '\n';
    
    return 0;
}