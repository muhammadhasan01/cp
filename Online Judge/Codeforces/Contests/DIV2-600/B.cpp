#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n;
ll a[N];
vector<int> ans;
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum != 0 || n & 1) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1, c = 1; i <= n; i++, c++) {
        if (a[i] < 0) {
            int k = -a[i];
            if (m[k] > 0) {
                if (--m[k] == 0) {
                    m.erase(k);
                    if ((int) m.size() == 0) {
                        ans.push_back(c);
                        c = 0;
                    }
                }
            } else {
                cout << -1 << '\n';
                return 0;
            }
        } else {
            m[a[i]]++;
        }
    }
    if ((int) m.size() > 0) {
        cout << -1 << '\n';
        return 0;
    }
    int pos = 0;
    for (int i = 0; i < (int) ans.size(); i++) {
        int e = ans[i];
        int cnt = 0;
        map<int,int> t;
        while (cnt < e) {
            cnt++, pos++;
            t[a[pos]]++;
            if (t[a[pos]] > 1) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 1; i <= len; i++) {
        cout << ans[i - 1] << (i == len ? '\n' : ' ');
    }

    return 0;
}
