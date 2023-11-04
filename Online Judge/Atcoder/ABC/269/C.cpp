#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long x;
    cin >> x;
    deque<long long> res;
    for (long long i = x; i > 0; i = x & (i - 1)) {
        res.emplace_front(i);
    }
    res.emplace_front(0);
    for (long long val : res) {
        cout << val << '\n';
    }
    
    return 0;
}