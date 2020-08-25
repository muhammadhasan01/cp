#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    int cur = 0;
    for (int it = 0; it < k; it++) {
        int x; cin >> x;
        int len = v.size();
        cur = (cur + x) % len;
        cout << v[cur] << (it == k - 1 ? '\n' : ' ');
        v.erase(v.begin() + cur);
    }

    return 0;
}