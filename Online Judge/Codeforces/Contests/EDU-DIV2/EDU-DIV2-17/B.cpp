#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int n;
vector<int> v[2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    vector<int> val = {a, b, c};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; string str;
        cin >> x >> str;
        v[(str[0] == 'P')].emplace_back(x);
    }
    vector<int> rem;
    int ans = 0;
    long long cost = 0;
    for (int it = 0; it < 2; it++) {
        sort(v[it].begin(), v[it].end());
        int len = v[it].size();
        for (int j = 0; j < len; j++) {
            if (j + 1 <= val[it]) {
                ++ans;
                cost += v[it][j];
            } else {
                rem.emplace_back(v[it][j]);
            }
        }
    }
    sort(rem.begin(), rem.end());
    int len = rem.size();
    for (int i = 0; i < min(len, c); i++) {
        cost += rem[i]; 
        ++ans;
    }
    cout << ans << ' ' << cost << '\n';

    return 0;
}