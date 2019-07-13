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

int tc;
string a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> a;
        string tmp = a;
        reverse(tmp.begin(),tmp.end());
        if(tmp == a){
            int k = LEN(a), cnt = 0;
            for(int i=0;i<k;i++){
                if(a[i] == a[0]){
                    cnt++;
                }
            }
            if(cnt == k){
                cout << "-1\n";
            }else{
                if(k&1){
                for(int i=0;i<=k/2;i++){
                    if(a[i] != a[0]){
                        swap(a[i],a[0]);
                        break;
                    }
                }
                    cout << a << "\n";
                }else{
                    for(int i=0;i<k/2;i++){
                        if(a[i] != a[0]){
                            swap(a[i],a[0]);
                            break;
                        }
                    }
                    cout << a << "\n";
                }
            }
        }else{
            cout << a << "\n";
        }

    }

    return 0;
}
