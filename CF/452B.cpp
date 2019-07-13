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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n;
int a[30];
vector<int> c1 = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
vector<int> c2 = {31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>n;
    forn(i,0,n-1)cin >> a[i];
    bool ok = false;
    int k = sz(c1);
    forn(i,0,k-n){
        bool cek = true;
        forn(j,0,n-1){
            if(a[j] != c1[i+j]){
                cek = false;
                break;
            }
        }
        if(cek)ok = true;
    }


    forn(i,0,k-n){
        bool cek = true;
        forn(j,0,n-1){
            if(a[j] != c2[i+j]){
                cek = false;
                break;
            }
        }
        if(cek)ok = true;
    }

    cout << (ok ? "Yes" : "No") << "\n";

    return 0;
}
