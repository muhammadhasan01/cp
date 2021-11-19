#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto dismiss = [&]() {
        puts("-1");
        exit(0);
    };

    long long k, a, b;
    cin >> k >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    if (a < k) {
        if (b % k != 0) {
            dismiss();
        }
    }
    cout << a / k + b / k << '\n';
    
    return 0;
}