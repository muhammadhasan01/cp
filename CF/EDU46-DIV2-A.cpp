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

int n;
string a[104],b[104];
// M,L,S,XL,XS,XXL,XXS,XXXl,XXXS
int f[15];
vector<string> v = {"M","L","S","XL","XS","XXL","XXS","XXXL","XXXS"};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        string s; cin >> s;
        if(s == "M"){
            f[1]--;
        }else if(s == "L"){
            f[2]--;
        }else if(s == "S"){
            f[3]--;
        }else if(s == "XL"){
            f[4]--;
        }else if(s == "XS"){
            f[5]--;
        }else if(s == "XXL"){
            f[6]--;
        }else if(s == "XXS"){
            f[7]--;
        }else if(s == "XXXL"){
            f[8]--;
        }else if(s == "XXXS"){
            f[9]--;
        }
    }

    forn(i,1,n){
        string s;
        cin >> s;
        if(s == "M"){
            f[1]++;
        }else if(s == "L"){
            f[2]++;
        }else if(s == "S"){
            f[3]++;
        }else if(s == "XL"){
            f[4]++;
        }else if(s == "XS"){
            f[5]++;
        }else if(s == "XXL"){
            f[6]++;
        }else if(s == "XXS"){
            f[7]++;
        }else if(s == "XXXL"){
            f[8]++;
        }else if(s == "XXXS"){
            f[9]++;
        }
    }

    int ans = 0;
    forn(i,1,9){
        if(f[i] > 0){
            ans += f[i];
        }
    }
    cout << ans << "\n";



    return 0;
}
