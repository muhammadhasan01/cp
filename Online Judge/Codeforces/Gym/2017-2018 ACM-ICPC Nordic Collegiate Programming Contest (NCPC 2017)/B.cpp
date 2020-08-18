#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const double INF = 1e18;

struct Runner {
    string name;
    double a, b;
    bool operator<(const Runner& other) {
        return b < other.b;
    };
};

int n;
Runner r[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i].name >> r[i].a >> r[i].b;
    }
    sort(r + 1, r + 1 + n);
    double ans = INF;
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        double cur = r[i].a;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            ++cnt;
            cur += r[j].b;
            if (cnt == 3) break;
        }
        if (cur < ans) {
            ans = cur;
            pos = i;
        }
    }
    vector<string> names;
    names.emplace_back(r[pos].name);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == pos) continue;
        ++cnt;
        names.emplace_back(r[i].name);
        if (cnt == 3) break;
    }
    cout << fixed << setprecision(6) << ans << '\n';
    for (auto& name : names) {
        cout << name << '\n';
    }

    return 0;
}