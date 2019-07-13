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
#define maximal 1000000000
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x[6] = {"Time","Mind","Soul","Power","Reality","Space"};
    string y[6] = {"green","yellow","orange","purple","red","blue"};
    map<string,int> m;
    for(int i=0;i<6;i++){
        m[y[i]] = i+1;
    }
    int n;
    cin >> n;
    if(n==0){
        cout << 6-n << "\n";
        for(int i=0;i<6;i++){
            cout << x[i] << "\n";
        }
        return 0;
    }
    string t;
    for(int i=1;i<=n;i++){
        cin >> t;
        m[t] = 0;
    }
    cout << 6-n << "\n";
    for(int i=0;i<6;i++){
        if(m[y[i]] != 0){
            cout << x[i] << "\n";
        }
    }
    return 0;
}
