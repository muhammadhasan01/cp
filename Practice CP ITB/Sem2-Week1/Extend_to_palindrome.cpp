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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e5+3;
string a,b;
int lps[N];

void solve(){
    int la = LEN(a), lb = LEN(a);
    b = a;
    reverse(all(b));
    //cerr << b << "\n";

    lps[0] = 0;
    int len = 0, i = 1, j = 0;
    while(i < lb){
        if(b[i] == b[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }

    i = 0;

    int k = 0;
    while(i < la){
        //cerr << i << " " << j << " => ";
        if(a[i] == b[j]){
            i++;
            j++;
        }
        else if(i < la && a[i] != b[j]){
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
        k = i-j;
        //cerr << i << " " << j << "\n";
    }

    //cerr << j << "\n";
    nrof(x,lb-1,j){
        cout << b[x];
    }
    cout << b << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> a){
        solve();
    }



    return 0;
}
