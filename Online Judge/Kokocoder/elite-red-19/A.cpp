#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long A, B;
    cin >> A >> B;
    long long ans = 0;
    while (A != B) {
        if (A > B) {
            swap(A, B);
        }
        long long X = (B - 1) / A;
        ans += X;
        B = B - X * A;
    }
    cout << ans << '\n';
    
    return 0;
}