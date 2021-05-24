#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;

void solve(){
    string s;
    cin >> s;
    unordered_map<string, int> cnt;
    int ans = 0;
    int n = s.size();
    for (int i=0;i<n - 1;i++){
        string temp;
        temp.pb(s[i]); temp.pb(s[i + 1]);
        cnt[temp]++;
    }
    for (auto &x : cnt){
        ans++;
    }
    cout << ans << el;  
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}