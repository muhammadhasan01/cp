#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n;
int p[N], par[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            p[x] = i;
        }
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(p[i]);
            auto it = s.begin();
            auto it2 = s.end();
            it2--;
            cout << (abs(*it - *it2) + 1 == i ? 1 : 0);
        }
        cout << '\n';
    }

    return 0;
}
