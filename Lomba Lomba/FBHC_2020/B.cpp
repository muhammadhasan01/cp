#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;

void solve() {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        res += (x == 'A' ? 1 : -1);
    }
    cout << (abs(res) == 1 ? 'Y' : 'N') << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("B_input.txt","r",stdin);
    freopen("B_output.txt","w",stdout);

    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}