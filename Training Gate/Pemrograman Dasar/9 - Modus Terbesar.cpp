#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N; int a[N+2];
    a[0] = -1; a[N+1] = inf;
    for(int i=1;i<=N;i++)cin>>a[i];
    sort(a,a+N+2);
    int cnt = 1, best = -1, cntm = -1;
    for(int i=0;i<=N;i++){
        if(a[i]==a[i+1]){
            cnt++;
        }else{
            if(cnt > cntm){cntm = cnt;
            best = max(best,a[i]);
            }else if(cnt == cntm){
            best = max(best,a[i]);
            }
            cnt=1;
        }
    }

    cout << best << "\n";
    return 0;
}
