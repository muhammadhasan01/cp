#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    deque<int> v;
    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (v.back() < a[i]) {
            v.push_back(a[i]);
        } else {
            auto it = lower_bound(v.begin(), v.end(), a[i]);
            *it = a[i];
        }
    }
    cout << v.size() - 1 << '\n';

    return 0;
}
