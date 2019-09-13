#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 5;
int n;
struct st {
    long long v, d, p;
};
st a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v >> a[i].d >> a[i].p;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i].p >= 0) {
            ans.push_back(i);
            long long dec = 0;
            for (int j = i + 1, k = a[i].v; j <= n; j++) {
                if (a[j].p < 0) continue;
                a[j].p -= (k + dec);
                if (a[j].p < 0) dec += a[j].d;
                if (k > 0) k--;
            }
        }
    }
    int k = ans.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << ans[i] << (i == k - 1 ? '\n' : ' ');
    }

    return 0;
}
