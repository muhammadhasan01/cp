#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) {
            even.emplace_back(x);
        } else {
            odd.emplace_back(x);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<int> a(n);
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[i] = even[j++];
        } else {
            a[i] = odd[k++];
        }
    }
    cout << (is_sorted(a.begin(), a.end()) ? "Yes" : "No") << '\n';
    
    return 0;
}