#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
typedef pair<string,pair<int,char> > psc;

const int N = 1e5+5;
const int M = N/2;
pair<pair<string,string>, pair<string,string>> ans[M];
int n;
psc s[N], ns[N];
pair<string,string> v[N];
pair<string,string> v2[N];

bool cmpr(psc a, psc b){
    if(a.ss.ss == b.ss.ss){
        return a.ss.ff < b.ss.ff;
    }
    return a.ss.ss < b.ss.ss;
}

bool cmpr2(psc a, psc b){
    return a.ss.ff < b.ss.ff;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        cin >> s[i].ff;

        int cnt = 0;
        char k;
        for(auto e:s[i].ff){
            if(e == 'a' || e == 'i' || e == 'u' || e == 'e' || e == 'o'){
                cnt++;
                k = e;
            }
        }
        s[i].ss.ff = cnt;
        s[i].ss.ss = k;
    }

    if(n < 4){puts("0"); ex;}

    sort(s+1,s+1+n, cmpr); // ok

    s[n+1].ss.ff = -1, s[n+1].ss.ss = '#';

    int k1 = 0, k2 = 0;
    for(int i=1;i<=n;i++){
        // containing both vowels and counts
        if(s[i].ss.ff == s[i+1].ss.ff && s[i].ss.ss == s[i+1].ss.ss){
            v[++k1] = {s[i].ff, s[i+1].ff}; // ok
            i++;
        }else{
            ns[++k2] = s[i];
        }
        //cerr << s[i].ff << " => " << s[i].ss.ff << " => " << s[i].ss.ss << "\n";
    }

    /*cerr << "\n";
    forn(i,1,k1){
        cerr << v[i].ff << " " << v[i].ss << '\n';
    }cerr << "\n";


    cerr << "--- leftover ---" << "\n";
    forn(i,1,k2){
        cerr << ns[i].ff << " " << ns[i].ss.ff << " " << ns[i].ss.ss << "\n";
    }cerr << "\n";*/


    sort(ns+1,ns+1+k2, cmpr2);


    int k3 = 0;
    for(int i=1;i<=k2-1;i++){
        if(ns[i].ss.ff == ns[i+1].ss.ff){
            v2[++k3] = {ns[i].ff, ns[i+1].ff};
            i++;
        }
    }

    /*cerr << "left222---\n";
    forn(i,1,k3){
        cerr << v2[i].ff << " " << v2[i].ss << "\n";
    }cerr << "\n";

    cerr << k1 << " and " << k3 << "\n";*/

    int lans = 0;

    for(int i=1;i<=min(k1,k3);i++){
        lans++;
        ans[lans].ff = v2[i];
        ans[lans].ss = v[i];
    }

    for(int i=k3+1;i<=k1;i+=2){
        if(i+1 <= k1){
            lans++;
            ans[lans].ff = v[i];
            ans[lans].ss = v[i+1];
        }
    }

    cout << lans << "\n";
    forn(i,1,lans){
        cout << ans[i].ff.ff << " " << ans[i].ss.ff << "\n";
        cout << ans[i].ff.ss << " " << ans[i].ss.ss << "\n";
    }


    return 0;
}
