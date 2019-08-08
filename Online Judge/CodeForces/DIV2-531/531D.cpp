#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define rofn(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,a,b,c;
string ss;
int f[4];

string answer(string s){
    if(b > 0){
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1' && b > 0){
                s[i] = '2';
                b--;
            }
        }
        return s;
        // ok
    }else if(b < 0){
        forn(i,0,n-1){
            if(s[i] == '2' && b < 0){
                s[i] = '1';
                b++;
            }
        }
        return s;
        // ok
    }else{
        return s;
    }
} // ok

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ss;
    for(auto e:ss){
        if(e == '0'){
            f[0]++;
        }else if(e == '1'){
            f[1]++;
        }else if(e == '2'){
            f[2]++;
        }
    }

    //cout << f[0] << " " << f[1] << " " << f[2] << "\n";

    if(f[0] == f[1] && f[1] == f[2]){
        cout << ss << "\n";
        return 0;
    }

    int tgt = n/3;
    a = f[0]-tgt, b = f[1]-tgt, c = f[2]-tgt;
    //cout << a << " " << b << " " << c << "\n";
    // ok
    if(a == 0){
        cout << answer(ss) << "\n"; // ok
    }else if(a > 0){
        for(int i=n-1;i>=0;i--){
            if(ss[i] == '0' & a > 0){
                if(c < 0){
                    ss[i] = '2';
                    c++;
                }else{
                    ss[i] = '1';
                    b++;
                }
                a--;
            }
        }
        // ok
        //cout << a << " " << b << " " << c << " ";
        cout << answer(ss) << "\n";
    }else if(a < 0){

        forn(i,0,n-1){
            if(ss[i] == '1' && a < 0){
                if(b > 0){
                    a++;
                    b--;
                    ss[i] = '0';
                }
            }else if(ss[i] == '2' && a < 0){
                if(c > 0){
                    a++;
                    c--;
                    ss[i] = '0';
                }
            }
        }
        //cout << s << "\n";
        //cout << b << " " << c << "\n";

        cout << answer(ss) << "\n";
    }

    return 0;
}
