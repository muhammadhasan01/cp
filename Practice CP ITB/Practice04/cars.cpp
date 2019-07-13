#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define ff first
#define ss second
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 100000;
int n;
int a[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    if(n<=2){cout<<"YES\n"; return 0;}
    stack<int> s;
    int chk = 1, i = 1;
    s.push(a[i]);
    while(i <= n){
        if(s.top() == chk){
            chk++;
            s.pop();
            while(!s.empty() && s.top() == chk){
                s.pop();
                chk++;
            }
            i++;
            if(i<=n){s.push(a[i]);}
        }else{
            i++;
            s.push(a[i]);
        }
    }
    if(s.size()==0){cout << "YES\n";}else{cout << "NO\n";}
    return 0;
}
