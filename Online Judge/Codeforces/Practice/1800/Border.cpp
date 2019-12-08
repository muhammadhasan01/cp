#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        g = __gcd(g, x);
    }
    set<int> ans;
    long long s = 0;
    for (int i = 0; i < k; i++) {
        ans.insert(s % k);
        s += (1LL) * g;
    }
    cout << ans.size() << '\n';
    auto it = ans.begin();
    while (1) {
        cout << *it;
        it++;
        if (it == ans.end()) {
            cout << '\n';
            break;
        } else {
            cout << ' ';
        }
    }

    return 0;
}
