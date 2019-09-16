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
    LL x;
    LL f[55];
    f[0]=0;
    f[1]=1;
    f[2]=1;
    for (int i=3;i<=50;i++) {
        f[i] = f[i-1] + f[i-2];
    }
    while (cin >> x) {
        if (x==0) return 0;
        else if (x==1) cout << "We're Dead" << endl;
        else {
            int p = upper_bound(f, f + 51, x) - f - 1;
            if (f[p] == x) {
                cout << "I'm Dead" << endl;
            } else {
                x-=f[p];
                //cout << x << endl;
                while (1) {
                    int g = upper_bound(f, f + 51, x) - f - 1;
                    for (int i=0;i<=50;i++) {
                        if (x>=f[i]) g=i;
                    }
                    if (x == f[g]) break; else x-=f[g];
                }
                cout << x << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
