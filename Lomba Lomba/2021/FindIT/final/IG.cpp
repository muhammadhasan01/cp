#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l = 1, r = 9;
    for (int i=1; i<=100; i++){
        int m = (l + r) / 2;
        cout << m << endl;
        int res;
        cin >> res;
        if (res == 2){
            r = m - 1;
        } else if (res == 1){
            r = m;
            l = m;
            cout << i << endl;
            return 0;
        } else{
            l = m + 1;
        }
    }

    return 0;
}