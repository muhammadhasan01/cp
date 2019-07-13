#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef pair<long double, long double> pld;

ll n;
int k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    int p = 0;
    while(p!=k){
        if(n%10 != 0){
            n--;
        }else{
            n/=10;
        }
        p++;
    }
    cout << n << "\n";
    return 0;
}
