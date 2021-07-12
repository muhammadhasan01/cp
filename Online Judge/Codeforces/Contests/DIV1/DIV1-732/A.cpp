#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

void solve() {
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) {
            odd.emplace_back(a[i]);
        } else {
            even.emplace_back(a[i]);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for (int i = 1, j = 0, k = 0; i <= n; i++) {
        if (i & 1) {
            a[i] = odd[j++];
        } else {
            a[i] = even[k++];
        }
    }
    cout << (is_sorted(a + 1, a + 1 + n) ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}