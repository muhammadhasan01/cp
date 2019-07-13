#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Vasya and Golden Ticket

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; string m; cin >> n >> m;
    n = m.size();
    int k;
    for(int i=0;i<n;i++){
        k += m[i]-int('0');
    }
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            int x = i, c = 0;
            for(int j=0;j<n;j++){
                x -= m[j]-int('0');
                if(x==0){x=i;c++;}
                if(x<0){c= 0;break;}
            }
            if(c>=2){cout << "YES\n"; return 0;}
            x =k/i, c = 0;
            for(int j=0;j<n;j++){
                x -= m[j]-int('0');
                if(x==0){x=k/i;c++;}
                if(x<0){c = 0;break;}
            }
            if(c>=2){cout << "YES\n"; return 0;}
        }
    }
    cout << "NO\n";
    return 0;
}
