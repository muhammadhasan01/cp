#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

int n;
vector<int> vec;

int main() {
    cin >> n;
    vec.resize(n + 1);
    for (int i=2;i<=n;i++){
        cin >> vec[i];
    }
    vec[2] = 1;
    int last = 2;
    vector<int> mx(n + 1, INF);
    for (int i=2;i<=n;i++){
        if (vec[i]) last = i;
        mx[i] = min(mx[i], i - last + 1);
    }
    last = INF;
    for (int i=n;i>=2;i--){
        if (vec[i]) last = i;
        // mx[i] = min(mx[i], last - i + 1);
        if (last <= n) mx[i] = min(mx[i], 2);
    }
    int ans = 1;
    for (int i=2;i<=n;i++) ans = max(ans, mx[i]);
    cout << ans << '\n';

    return 0;
}