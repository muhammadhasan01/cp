#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 5;
const long long INF = 1e18;

typedef pair<long long, long long> pll;

int n;
pll p[N];

bool intersect(pll x, pll y) {
    if (x.first > y.first) swap(x, y);
    return (y.first <= x.second);
}

bool can(int s, int d, int idx) {
    pll cur = make_pair(s, s + d - 1);
    for (int i = 1; i < idx; i++) {
        if (intersect(cur, p[i])) {
            return false;
        }
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long s, d;
        cin >> s >> d;
        if (can(s, d, i)) {
            p[i] = make_pair(s, s + d - 1);
        } else {
            long long pos = INF;
            for (int j = 0; j < i; j++) {
                long long cur = p[j].second + 1;
                if (can(cur, d, i))
                    pos = min(pos, cur);
            }
            p[i] = make_pair(pos, pos + d - 1);
        }
        cout << p[i].first << " " << p[i].second << '\n';
    }
    
    return 0;
}