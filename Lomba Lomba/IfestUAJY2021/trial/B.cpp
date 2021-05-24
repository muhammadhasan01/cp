#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 5;

long double EUY[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    int pos = n - 1;
    while ((int) v.size() > 1) {
        int len = v.size();
        if (len == 1) break;
        pos = ((pos + m) + len) % len;
        v.erase(v.begin() + pos);
        --pos;
    }
    cout << v[0] << '\n';

    return 0;
}