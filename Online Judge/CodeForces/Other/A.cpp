#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,k;
int a[103];
unordered_map<int,int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    int maxi = -1;
    forn(n){cin >> a[i]; m[a[i]]++; maxi = max(m[a[i]],maxi);}
    //cout << m.size() << "\n";
    //cout << maxi << "\n";
    int sets = (int)m.size();
    int dish = 1;
    if(maxi > k){
        dish +=  maxi/k;
        if(maxi%k == 0)dish--;
    }
    //cout << sets << " " << dish << "\n";
    cout << sets*dish*k-n << "\n";
    return 0;
}
