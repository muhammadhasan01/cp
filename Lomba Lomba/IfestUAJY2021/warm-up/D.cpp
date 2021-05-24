#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            even.emplace_back(x);
        } else {
            odd.emplace_back(x);
        }
    }
    if ((int) odd.size() > (int) even.size()) {
        odd.swap(even);
    }
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());
    vector<int> ans;
    while (true) {
        if (even.empty()) break;
        ans.emplace_back(even.back());
        even.pop_back();
        if (odd.empty()) break;
        ans.emplace_back(odd.back());
        odd.pop_back();
    }
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }

    return 0;
}