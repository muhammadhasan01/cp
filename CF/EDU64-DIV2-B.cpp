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

int tc;
string s;

bool cek(string k){
    int n = len(k);
    forn(i,0,n-2){
        if(abs(k[i] - k[i+1]) == 1)return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> s;
        string s1 = "", s2 = "";
        for(auto e:s){
            if(int(e)&1){
                s1 += e;
            }else{
                s2 += e;
            }
        }
        sort(all(s1)); sort(all(s2));
        if(cek(s1+s2)){
            cout << s1 << s2 << "\n";
        }else if(cek(s2+s1)){
            cout << s2 << s1 << "\n";
        }else{cout << "No answer\n";}

    }


    return 0;
}
