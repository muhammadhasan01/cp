#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = a[s];
    } else {
        int m = (s + e) >> 1;
        build(2 * v, s, m);
        build(2 * v + 1, m + 1, e);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

void update(int v, int s, int e, int l, int r) {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;
}
