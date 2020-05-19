// author: mhasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 2e9;

struct st {
    int lowVal, idx;
    long long val;
    bool operator<(const st& other) {
        if (val == other.val) {
            return lowVal > other.lowVal;
        }
        return val > other.val;
    }
};

int n;
long long m;
st p[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].val >> p[i].lowVal;
        p[i].idx = i;
    }
    sort(p + 1, p + 1 + n);
    int minNum = n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += p[i].val;
        if (sum >= m) {
            minNum = i;
            break;
        }
    }
    vector<pair<long long, int>> v[2];
    for (int i = 1; i <= n; i++) {
        v[1 - p[i].lowVal].push_back({p[i].val, p[i].idx});
    }
    int l1 = v[0].size();
    int l2 = v[1].size();
    vector<long long> pre(l2 + 5);
    for (int i = 1; i <= l2; i++) {
        pre[i] = v[1][i - 1].first + pre[i - 1];
    }
    int maxLow = 0;
    long long curSum = 0;
    for (int i = 1; i <= min(l1, minNum); i++) {
        curSum += v[0][i - 1].first;
        if (minNum - i > l2 || minNum - i < 0) continue;
        if (curSum + pre[minNum - i] >= m) {
            maxLow = i;
        }
    }
    vector<int> ans;
    for (int i = 0; i < maxLow; i++) ans.push_back(v[0][i].second);
    for (int i = 0; i < minNum - maxLow; i++) ans.push_back(v[1][i].second);
    cout << minNum << ' ' << maxLow << '\n';
    for (int i = 0; i < minNum; i++) {
        cout << ans[i] << (i == minNum - 1 ? '\n' : ' ');
    }

    return 0;
}