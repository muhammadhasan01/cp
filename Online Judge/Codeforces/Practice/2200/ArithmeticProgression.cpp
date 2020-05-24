#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;

int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int l = 0, r = INF, maxVal = 0;
    int cnt = 0;
    vector<int> v;
    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << "> " << mid << endl;
        ++cnt;
        char x;
        cin >> x;
        if (x == '0') {
            r = mid - 1;
            maxVal = mid;
        } else {
            l = mid + 1;
        }
    }
    v.push_back(maxVal);
    vector<int> id(n);
    iota(id.begin(), id.end(), 1);
    int randRange = n;
    for (int i = 1; i <= min(n, 60 - cnt); i++) {
        int idx = rng32() % randRange; 
        cout << "? " << id[idx] << endl;
        int val;
        cin >> val;
        randRange--;
        swap(id[idx], id[randRange]);
        if (val == maxVal) continue;
        v.push_back(val);
    } 
    sort(v.begin(), v.end());
    int len = v.size();
    int g = 0;
    for (int i = 1; i < len; i++) {
        g = __gcd(g, (v[i] - v[i - 1]));
    }
    int a = maxVal - g * (n - 1);
    cout << "! " << a << " " << g << endl;

    return 0;
}