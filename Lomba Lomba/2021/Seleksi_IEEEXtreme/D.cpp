#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            pos.emplace_back(i);
        }
    }
    int len = pos.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << pos[i] << " \n"[i == len - 1];
    }
    
    return 0;
}