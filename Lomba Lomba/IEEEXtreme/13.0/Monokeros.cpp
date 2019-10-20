#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;
int n;
set<pair<int,int>> s;
int head[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    s.insert({-inf, 0});
    s.insert({inf, 0});
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto its = s.lower_bound({x, -inf});
        auto itb = its;
        its--;
        int k = min(itb -> second, its -> second);
        head[i] = - (k - 1);
        s.insert({x, k - 1});
    }

    for (int i = 1; i <= n; i++) {
        cout << head[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
