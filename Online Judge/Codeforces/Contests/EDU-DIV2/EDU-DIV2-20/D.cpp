#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, k;
string ad;
vector<int> values;

bool can(int x) {
    int cur = 0;
    int lastPos = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        cur += values[i];
        if (cur > x) {
            if (i == lastPos) return false;
            cur = 0;
            lastPos = i--;
            ++cnt;
        }
    }
    return (cnt <= k);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    cin.ignore();
    getline(cin, ad);
    stringstream SS(ad);
    string str;
    while (SS >> str) {
        int cnt = 0;
        for (char CC : str) {
            ++cnt;
            if (CC == '-') {
                values.emplace_back(cnt);
                cnt = 0;
            }
        }
        values.emplace_back(++cnt);
    }
    int val = values.back();
    values.pop_back();
    values.emplace_back(val - 1);
    n = values.size();
    int l = 0, r = INF, ans = INF;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}