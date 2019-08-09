#include<bits/stdc++.h>
using namespace std;

string s;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int l = 0, r = 0, sz = s.length();
    vector<int> place;
    place.push_back(-1);
    for (int i = 0; i < sz - 3; i++) {
        if (s.substr(i,4) == "bear") {
            place.push_back(i);
        }
    }

    int len = place.size();
    long long ans = 0;
    for (int i = 1; i < len; i++) {
        ans += (1LL) * (place[i] - place[i-1]) * (1LL) * (sz - (place[i] + 4) + 1);
    }
    cout << ans << '\n';

    return 0;
}
