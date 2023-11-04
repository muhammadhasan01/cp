#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long base = sum / n;
    long long rem = sum % n;
    vector<long long> b(n, base);
    for (int i = 0; i < rem; i++) {
        b[i]++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long dif = 0;
    for (int i = 0; i < n; i++) {
        dif += abs(a[i] - b[i]);
    }
    cout << dif / 2 << '\n';
    
    return 0;
}