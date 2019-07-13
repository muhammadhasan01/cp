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
using namespace std;

const int NMAX = 2879;
int A,B;
int a[NMAX+3], b[NMAX+3];
pair<int,int> c[2*NMAX+3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A;
    int hlft = 4*12*30, ans = 0;
    //cout << hlft << "\n";
    for(int i=1;i<=A;i++){
        cin >> a[i];
        c[i].ff = a[i]; c[i].ss = 1;
        if(a[i] <= hlft){
            ans++;
        }
    }
    cin >> B;
    for(int i=1;i<=B;i++){
        cin >> b[i];
        c[i+A].ff = b[i]; c[i+A].ss = 2;
        if(b[i] <= hlft){
            ans++;
        }
    }

    int len = A+B;
    sort(c+1,c+len+1);
    int c1 = 0, c2 = 0, c3 = 0;
    bool ovt = false, tvo = true;
    for(int i=1;i<=len;i++){
        //cout << "(" << c[i].ff << "," << c[i].ss << ")" << " => ";
        if(c[i].ss == 1){
            c1++;
        }else if(c[i].ss == 2){
            c2++;
        }
        if(i==1 && c1 > c2){
            ovt = true;
        }else if(i==1 && c2 > c1){
            tvo = true;
        }
        if(i > 1 && ovt && c2 > c1){
            //cout << "YES";
            ovt = false;
            tvo = true;
            c3++;
        }else if(i > 1 && tvo && c1 > c2){
            //cout << "YES";
            ovt = true;
            tvo = false;
            c3++;
        }else{
            //cout << "NO";
        }
        //cout << "\n";
    }
    cout << ans << "\n";
    cout << c3 << "\n";
    return 0;
}
