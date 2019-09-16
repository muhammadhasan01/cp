#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL a,b;
    cin >> a >> b;
    LL p[65];
    p[0]=1;
    for (int i=1;i<=64;i++) p[i]=p[i-1]*2;
    if (p[a-1]>=b) cout << "menang"; else cout << "kalah";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
