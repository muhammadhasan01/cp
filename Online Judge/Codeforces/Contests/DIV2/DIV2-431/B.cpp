#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
long long y[N];

void choose(long long p, long long q) {
    long long dx = p - q;
    long long dy = y[p] - y[q];
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (i == p || q == i) continue;
        long long cdx = p - i;
        long long cdy = y[p] - y[i];
        if (dy * cdx == dx * cdy) continue;
        v.emplace_back(i);
    }
    int len = v.size();
    if (len == 0) {
        cout << "No" << '\n';
        exit(0);
    }
    for (int i = 1; i < len; i++) {
        long long cdx = v[0] - v[i];
        long long cdy = y[v[0]] - y[v[i]];
        if (dy * cdx != dx * cdy) return;
    }
    cout << "Yes" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) choose(1LL, i);
        if (i != 2) choose(2LL, i);
    }
    cout << "No" << '\n';

    return 0;
}