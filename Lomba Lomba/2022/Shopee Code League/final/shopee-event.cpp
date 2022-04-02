// Author: Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;

int n, k;
int par[N], sz[N];

int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < k; i++) {
        int len;
        cin >> len;
        int fst;

        if (len) cin >> fst;
        for (int j = 1; j < len; j++) {
            int a;
            cin >> a;
            make(fst, a);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << sz[find(i)] << ' ';
    }
    cout << '\n';

    return 0;
}