#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n, A;
vector<int> v[M];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> A;
    for (int i = 1; i <= n; i++) {
        int col;
        cin >> col;
        v[col].emplace_back(i);
    }
    int len = v[A].size();
    for (int i = 1; i < M; i++) {
        if (i == A) continue;
        int curlen = v[i].size();
        if (curlen == 0) continue;
        if (curlen < len) continue;
        bool flag = true;
        for (int j = 0; j < len; j++) {
            if (v[A][j] < v[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}