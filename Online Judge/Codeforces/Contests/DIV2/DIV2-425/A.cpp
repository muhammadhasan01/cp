#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long res = n / k;
    cout << (res & 1 ? "YES" : "NO") << "\n";

    return 0;
}