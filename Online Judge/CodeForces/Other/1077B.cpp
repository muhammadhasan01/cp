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

const int NMAX = 100;
int n;
int a[NMAX+2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++)cin>>a[i];
    bool ok = false;
    int ans = 0;
    map<int,int> m;
    for(int i=1;i<n-1;i++){
        if(a[i] == 1 && a[i+1] == 0 && a[i+2] == 1){
            //cout << "yea ";
            ans++;
            if(m[i] > 0){ans--; m[i+2] = 0;}else{
                m[i] = 1;
                m[i+2] = 1;
            }
        }
        //cout << i << " " << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}
