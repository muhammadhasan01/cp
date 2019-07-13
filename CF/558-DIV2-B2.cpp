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

const int N = 1e5+5;
int n;
int f[N],cnt[N],sm;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int x = 0;
    forn(i,1,n){
        int k; cin >> k;
        cnt[f[k]]--;
        f[k]++;
        cnt[f[k]]++;
        sm = max(sm, f[k]);
        bool flag = false;
        if(cnt[1] == i){
            flag = true;
        }else if(cnt[i] == 1){
            flag = true;
        }else if(cnt[1] == 1 && cnt[sm] * sm == i-1){
            flag = true;
        }else if(cnt[sm-1] * (sm-1) == i - sm && cnt[sm] == 1){
            flag = true;
        }
        if(flag)x = max(x,i);
    }
    cout << x << "\n";


    return 0;
}
