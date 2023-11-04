#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    vector<int> t(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> b[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int& i, int& j) {
        return t[i] > t[j];
    });
    for (int i = n - 1; i >= 0; i--) {
        int num = a[ord[i]];
        for (int rep = 0, j = i; rep < num; rep++, j++) {
            swap(ord[j], ord[j + 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ord[i] + 1 << " \n"[i == n - 1];
    }
    
    return 0;
}