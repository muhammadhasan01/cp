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

int x;
vector<int> a(3);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> a[0] >> a[1] >> a[2];

    sort(all(a));
    int sum = a[0]+a[1]+a[2];
    int n = x/sum;
    sum = sum*n;
    //cout << n << "\n";
    n = 3*n;
    int i = 0;
    while(sum < x){
        sum += a[i];
        i++;
        if(sum > x)break;
        n++;
    }
    cout << n << "\n";
    return 0;
}
