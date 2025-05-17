#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<long long, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    vector<long long> days;
    days.reserve(2 * n);
    for (int i = 0; i < n; i++) {
        days.emplace_back(a[i] + 1);
        days.emplace_back(a[i] + 2);
    }
    sort(days.begin(), days.end());
    days.erase(unique(days.begin(), days.end()), days.end());
    bool can = false;
    int D = days.size();
    for (int i = 0; i < D && !can; i++) {
        int j = i;
        while (j + 1 < D && days[j + 1] == days[j] + 1) {
            j++;
        }
        int L = j - i;
        if (L > 0) {
            vector<int> m(L);
            for (int e = 0; e < L; e++) {
                m[e] = mp[days[i + e] - 1];
            }
            for (int e = 0; e < L; e++) {
                if (m[e] >= 4) {
                    can = true;
                    break;
                }
            }
            if (can) {
                i = j;
                continue;
            }
            int e = 0;
            while (e < L && !can) {
                if (m[e] >= 1) {
                    int countBig = 0;
                    while (e < L && m[e] >= 1) {
                        if (m[e] >= 2) {
                            countBig++;
                        }
                        e++;
                    }
                    if (countBig >= 2) {
                        can = true;
                        break;
                    }
                } else {
                    e++;
                }
            }
        }
        i = j;
    }
    cout << (can ? "Yes" : "No") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}