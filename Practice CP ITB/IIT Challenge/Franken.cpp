#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define first ff
#define second ss
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;


int n;
ll tj,tf,mj,mf,aj,af;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> tj >> tf >> mj >> mf >> aj >> af;
        if(mf>mj){
            cout << "RUN-ERROR\n";
        }else if(tf > tj){
            cout << "TIMELIMIT\n";
        }else if(aj != af){
            cout << "WRONG-ANSWER\n";
        }else{
            cout << "CORRECT\n";
        }
    }
    return 0;
}
