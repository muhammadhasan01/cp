#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n, p[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        vector<int> v;
        v.emplace_back(p[1]);
        for (int i = 2; i <= n - 1; i++) {
            int cur = v.back();
            if (abs(cur - p[i]) + abs(p[i] - p[i + 1]) == abs(cur - p[i + 1])) continue;
            v.emplace_back(p[i]);
        }
        v.emplace_back(p[n]);
        int len = v.size();
        cout << len << '\n';
        for (int i = 0; i < len; i++) {
            cout << v[i] << (i == len - 1 ? '\n' : ' ');
        }
    }

    return 0;
}