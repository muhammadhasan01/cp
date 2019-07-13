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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if(n < 25){
        cout << "-1\n";
    }else{
        bool flag = false;
        int k = -1;
        for(int i=2;i*i<=n;i++){
            if(n%i == 0){
                if(i >= 5 && n/i >= 5){
                    k = i;
                    flag = true;
                    break;
                }
            }
        }

        if(!flag){
            cout << "-1\n";
        }else{
            string t = "aiueo";
            forn(i,0,k-1){
                forn(j,0,n/k-1){
                    cout << t[(i+j)%5];
                }
            }
        }

    }



    return 0;
}
