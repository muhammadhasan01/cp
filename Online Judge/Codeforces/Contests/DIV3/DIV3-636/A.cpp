#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

int tc;
long long n;
vector<long long> v;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long cur = 4;
    while (cur < INF) {
        v.push_back(cur - 1);
        cur <<= 1;
    }
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (auto& e : v) {
            if (n % e == 0) {
                cout << n / e << '\n';
                break;
            }
        }
    }

    return 0;
}