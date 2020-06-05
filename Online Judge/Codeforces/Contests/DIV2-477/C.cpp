#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n, m, cl, ce, cv;
long long v;
int q;
long long stair[N], elev[N];
long long p1, q1, p2, q2;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> cl >> ce >> v;
    for (int i = 1; i <= cl; i++) {
        cin >> stair[i];
    }
    for (int i = 1; i <= ce; i++) {
        cin >> elev[i];
    }
    cin >> q;
    while (q--) {
        cin >> p1 >> q1 >> p2 >> q2;
        if (p1 == p2) {
            cout << abs(q1 - q2) << '\n';
            continue;
        }
        vector<long long> temp = {q1, q2};
        long long ans = INF;
        if (cl) {
            vector<long long> stairpos;
            for (auto e : temp) {
                int pos = lower_bound(stair + 1, stair + 1 + cl, e) - stair;
                if (pos <= cl) stairpos.emplace_back(stair[pos]);
                if (pos - 1 >= 1) stairpos.emplace_back(stair[pos - 1]);
            }
            long long upstair = abs(p1 - p2);
            for (auto e : stairpos) {
                long long cur = upstair + abs(e - q1) + abs(e - q2);
                ans = min(ans, cur);
            }
        }
        if (ce) {    
            vector<long long> elevpos;
            for (auto e : temp) {
                int pos = lower_bound(elev + 1, elev + 1 + ce, e) - elev;
                if (pos <= ce) elevpos.emplace_back(elev[pos]);
                if (pos - 1 >= 1) elevpos.emplace_back(elev[pos - 1]);
            }
            long long upelev = (abs(p1 - p2) + v - 1) / v;
            for (auto e : elevpos) {
                long long cur = upelev + abs(e - q1) + abs(e - q2);
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}