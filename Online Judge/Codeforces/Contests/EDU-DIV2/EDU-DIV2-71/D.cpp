#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 3e5 + 5;
const int M = 998244353;
int n;
pii p[N];
long long ans = 0;
long long f[N];

bool c1(pii a, pii b) {
    return a.first < b.first;
}

bool c2(pii a, pii b) {
    return a.second < b.second;
}

long long mmod(long long a, long long b) {
    return (a % b + b) % b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    p[n + 1] = {-1, -1};
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= M;
    }
    ans = f[n];
    sort(p + 1, p + 1 + n, c1);
    int cnt = 1;
    long long cur = 1;
    for (int i = 1; i <= n; i++) {
        if (p[i].first == p[i + 1].first) {
            cnt++;
        } else {
            cur *= f[cnt];
            cur = mmod(cur, M);
            cnt = 1;
        }
    }
    ans -= cur, ans = mmod(ans, M);
    cur = 1, cnt = 1;
    sort(p + 1, p + 1 + n, c2);
    for (int i = 1; i <= n; i++) {
        if (p[i].second == p[i + 1].second) {
            cnt++;
        } else {
            cur *= f[cnt];
            cur = mmod(cur, M);
            cnt = 1;
        }
    }
    ans -= cur, ans = mmod(ans, M);
    sort(p + 1, p + 1 + n);
    bool ok = true;
    for (int i = 1; i < n; i++) {
        ok &= (p[i].first <= p[i + 1].first);
        ok &= (p[i].second <= p[i + 1].second);
        if (!ok) break;
    }
    if (ok) {
        cur = 1, cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (p[i] == p[i + 1]) {
                cnt++;
            } else {
                cur *= f[cnt];
                cur = mmod(cur, M);
                cnt = 1;
            }
        }
        ans += cur, ans = mmod(ans, M);
    }
    cout << mmod(ans, M) << '\n';

    return 0;
}
