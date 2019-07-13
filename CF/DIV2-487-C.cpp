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

pair<char,int> v[5];
char a[55][55];

bool cstm(pair<char,int> a, pair<char,int> b){
    return a.ss > b.ss;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    v[1].ff = 'A', v[2].ff = 'B', v[3].ff = 'C', v[4].ff = 'D';
    cin >> v[1].ss >> v[2].ss >> v[3].ss >> v[4].ss;
    sort(v+1,v+5,cstm);

    v[3].ss--; v[4].ss--;

    int k = 1;
    do{
        forn(i,1,50){
            if(!(i&1)){
                if(v[4].ss == 0){
                    a[k][i] = v[3].ff;
                }else{
                    a[k][i] = v[4].ff;
                    v[4].ss--;
                }
            }else{
                a[k][i] = v[3].ff;
            }
        }
        k++;
        forn(i,1,50)a[k][i] = v[3].ff;
        k++;
    }while(v[4].ss > 0);

    int j = 1;
    do{
        forn(i,1,50)a[k][i] = v[4].ff;
        k++;
        forn(i,1,50){
            if(v[j].ss == 0)j++;
            if(!(i&1) && j < 4){
                a[k][i] = v[j].ff;
                v[j].ss--;
            }else{
                a[k][i] = v[4].ff;
            }
        }
        k++;
    }while(v[1].ss > 0 || v[2].ss > 0 || v[3].ss > 0);

    k--;
    cout << k << " " << 50 << "\n";

    forn(i,1,k){
        forn(j,1,50){
            cout << a[i][j];
        }cout << "\n";
    }



    return 0;
}
