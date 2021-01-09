#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
ll d;

void pecat(string s) {
    cout << s << ", YOU ARE FIRED!";
}

void solve() {
    cin >> n >> d >> k;
    vector<pair<int, string>> emp(n);
    for (int i = 0; i < n; i++) {
        cin >> emp[i].second >> emp[i].first;
    }
    sort(emp.begin(), emp.end(), greater<>());
    ll tot = 0;
    for (int i = 0; i < k; i++) {
        tot += 1LL * emp[i].first;
    }
    if (tot < d) {
        cout << "impossible" << '\n';
    } else {
        cout << k << '\n';
        for (int i = 0; i < k; i++) {
            pecat(emp[i].second);
            cout << '\n';
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}