#include <bits/stdc++.h>

using namespace std;

const int K = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        st.emplace(x);
    }
    int x = n;
    for (int it = 0; it < K; it++, x++) {
        bool isGood = true;
        int y = x;
        while (y > 0) {
            int num = y % 10;
            if (st.find(num) != st.end()) {
                isGood = false;
                break;
            }
            y /= 10;
        }
        if (isGood) {
            cout << x << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    
    return 0;
}