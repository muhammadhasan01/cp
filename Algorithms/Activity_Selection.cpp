#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

// Solution : sort ascending by end time if different and sort by descending if end time is same 

struct s{
    int st, en, idx;
};

int tc, n;
s a[103];

bool cmpr(s a, s b){
    if(a.en == b.en){
        return a.st > b.st;
    }
    return a.en < b.en;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        form(i,n)cin>>a[i].st;
        form(i,n){
            cin >> a[i].en; a[i].idx = i+1;
        }
        sort(a,a+n,cmpr);
        /*form(i,n){
            cout << a[i].st << " " << a[i].en << " " << a[i].idx << "\n";
        }*/
        cout << a[0].idx;
        if(n>1)cout << " ";
        int now = a[0].en;
        for(int i=1;i<n;i++){
            if(a[i].st >= now){
                now = a[i].en;
                cout << a[i].idx;
                if(i != n-1)cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
