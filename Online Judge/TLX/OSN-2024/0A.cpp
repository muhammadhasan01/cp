#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long sum = 0;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.emplace(x - i);
        sum += x;
        long long cur = sum + 1LL * i * (i + 1) / 2;
        cout << *st.begin() + i << ' ' << *st.rbegin() + i << ' ';
        cout << fixed << setprecision(9) << (long double) cur / (i + 1) << '\n';
    }
    
    return 0;
}