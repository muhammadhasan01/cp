// author : Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int n;
string dig;
set<int> ada;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> dig;
        if (dig[0] == '-' || dig.size() > 7) continue;
        ada.insert(stoi(dig));
    }    
    int ans = 0;
    for (auto& x : ada){
        if (x != ans) break;
        ans++;
    }
    cout << ans << el;

    return 0;
}