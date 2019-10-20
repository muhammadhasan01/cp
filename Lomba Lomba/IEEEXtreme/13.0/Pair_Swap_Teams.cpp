#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
string s;

const int N = 2e5 + 5;
int pre[5][N], oc[5];
int pr[5][5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        memset(pre, 0, sizeof(pre));
        memset(oc, 0, sizeof(oc));
        cin >> s; s += s;
        n = s.size();
        s = '#' + s;

        for (int i = 1; i <= n; i++) {
            int x = s[i] - 'A' + 1;
            pre[x][i]++; if (i <= n / 2) oc[x]++;
            for (int t = 1; t <= 4; t++) {
                pre[t][i] += pre[t][i - 1];
            }

        }
        vector<int> v;
        for (int i = 1; i <= 4; i++) {
            if (oc[i] > 0) v.push_back(i);
        }
        int len = v.size();
        int ans = 1e9;
        do {
            for (int i = 1; i <= n / 2; i++) {
                memset(pr, 0, sizeof(pr));
                int inc = 0;
                for (int t = 0; t < len; t++) {
                    int le = i + inc, ri = i + inc + oc[v[t]] - 1;
                    for (int tt = 0; tt < len; tt++) {
                        if (tt == t) continue;
                        pr[v[t]][v[tt]] += (pre[v[tt]][ri] - pre[v[tt]][le - 1]);
                    }
                    inc += oc[v[t]];
                }
                // cerr << i << ":" << "("; for (auto e : v) cerr << char(e + int('A') - 1); cerr << ")\n";
                int cur = 0;
                for (int t = 0; t < len; t++) {
                    int sel = 0;
                    for (int tt = t + 1; tt < len; tt++) {
                        int ab = pr[v[t]][v[tt]];
                        int ba = pr[v[tt]][v[t]];
                        // cerr << char(v[t] + int('A') - 1) << " => " << char(v[tt] + int('A') - 1) << " => " << ab << '\n';
                        // cerr << char(v[tt] + int('A') - 1) << " => " << char(v[t] + int('A') - 1) << " => " << ba << '\n';
                        cur += min(ab, ba);
                        sel += abs(ab - ba);
                    }
                    if (sel){
                        cur += sel - (sel/3);
                    }
                }
                ans = min(ans, cur);
            }
            if (ans == 0) break;
        } while (next_permutation(v.begin(), v.end()));
        cout << ans << '\n';
    }

    return 0;
}
