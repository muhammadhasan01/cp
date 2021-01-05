#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair < int, int > ;

const int N = 1e3 + 10;
int n;
int ar[N];
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int ask() {
    for (int i = 1; i <= n; i++) {
        cout << ar[i];
    }
    cout << endl;
    int ret;
    cin >> ret;
    if (ret == n) exit(0);
    return ret;
}

void solve() {
    while (1) {
        for (int i = 1; i <= n; i++) {
            ar[i] = rng32() % 2;
        }
        if (ask()) break;
    }
    vector<int> sama, beda;
    ar[1] = !ar[1];
    for (int i = 2; i < n; i++) {
        ar[i] = !ar[i];
        if (ask()) {
            beda.pb(i);
        } else {
            sama.pb(i);
        }
        ar[i] = !ar[i];
    }
    if ((int) beda.size() < n / 2) {
        beda.pb(n);
    } else {
        sama.pb(n);
    }
    for (auto x: sama) {
        ar[x] = !ar[x];
    }
    ask();
    for (auto x: sama) {
        ar[x] = !ar[x];
    }
    ar[1] = !ar[1];
    for (auto x: beda) {
        ar[x] = !ar[x];
    }
    ask();
}

int main() {
    cin >> n;
    solve();

    return 0;
}