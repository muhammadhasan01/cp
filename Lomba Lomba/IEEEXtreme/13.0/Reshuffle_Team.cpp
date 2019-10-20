#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
string s;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s; s += s;
        n = s.size();
        s = '#' + s;
        vector<vector<int>> pre(5, vector<int>(n + 2, 0));
        vector<int> oc(5, 0);
        for (int i = 1; i <= n; i++) {
            int x = s[i] - 'A' + 1;
            pre[x][i]++; oc[x]++;
            for (int t = 1; t <= 4; t++) {
                pre[t][i] += pre[t][i - 1];
            }

        }
        vector<int> v;
        for (int i = 1; i <= 4; i++) {
            oc[i] /= 2;
            if (oc[i] > 0) v.push_back(i);
        }
        int len = v.size();
        int ans = 1e9;
        do {
            int get = 1e9;
            for (int i = 1; i <= n / 2; i++) {
                int ret = 0, inc = 0;
                for (int t = 0; t < len; t++) {
                    int le = i + inc, ri = i + inc + oc[v[t]] - 1;
                    ret += oc[v[t]] - (pre[v[t]][ri] - pre[v[t]][le - 1]);
                    inc += oc[v[t]];
                }
                get = min(get, ret);
            }
            ans = min(ans, get);
        } while (next_permutation(v.begin(), v.end()));
        cout << ans << '\n';
    }

    return 0;
}
