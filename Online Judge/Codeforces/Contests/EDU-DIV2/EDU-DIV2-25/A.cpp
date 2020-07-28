#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
char a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '0') {
            ans.emplace_back(cur);
            cur = 0;
        } else {
            ++cur;
        }
    }
    ans.emplace_back(cur);
    for (auto& e : ans) cout << e;
    cout << '\n';

    return 0;
}