#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Check whether a candidate window (given by a vector of the recent elements)
// has any pair (i, j) with (a[i] xor a[j]) >= k.
bool validPair(const vector<int>& window, int k) {
    int sz = window.size();
    for (int i = 0; i < sz; i++){
        for (int j = i + 1; j < sz; j++){
            if ((window[i] ^ window[j]) >= k)
                return true;
        }
    }
    return false;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
 
        // When k is 0, a single element (via self-pairing giving 0) is acceptable.
        if(k == 0) {
            cout << 1 << "\n";
            continue;
        }
 
        int ans = n + 1;
        // Two pointers: L = left index, R = right index (both 0-indexed).
        int L = 0;
        for (int R = 0; R < n; R++){
            // Try to "shrink" the window from the left as long as it remains valid.
            // Because of the 70-rule, we only need to check the last min(window_size, 70) elements.
            while(L < R) {
                int windowSize = R - L + 1;
                int startIndex = max(L, R - 69); // last 70 elements (or whole window if less than 70)
                vector<int> window;
                window.reserve(windowSize);
                for (int j = startIndex; j <= R; j++){
                    window.push_back(a[j]);
                }
                if(validPair(window, k)) {
                    ans = min(ans, windowSize);
                    // shrink the window further
                    L++;
                } else {
                    break;
                }
            }
        }
 
        if(ans == n + 1) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
