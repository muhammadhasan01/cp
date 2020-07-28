#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5;

int tc;
int n;
pair<int, int> p[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1, p + 1 + n);
    map<int, long long> mp;
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        int pos = p[i].first;
        int lpos = p[i].first - p[i].second;
        int rpos = p[i].first + p[i].second;
        long long lres = p[i].second + mp[lpos];
        long long rres = p[i].second + mp[pos];
        if (mp[p[i].first] < lres)
            mp[p[i].first] = lres;
        if (mp[rpos] < rres)
            mp[rpos] = rres;
        answer = max(answer, max(lres, rres));
    }
    cout << answer << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("C_input.txt", "r", stdin);
    freopen("C_output.txt", "w", stdout);

    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}