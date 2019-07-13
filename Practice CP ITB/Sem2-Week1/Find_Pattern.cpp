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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int q;
string s1,s2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--){
        cin >> s1 >> s2;
        int lps[LEN(s2)];
        int i = 1;
        lps[0] = 0;
        int len = 0;
        while(i < LEN(s2)){
            if(s2[i] == s2[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
            //cerr << 1 << " " << i << "\n";
        }

        i = 0;
        int j = 0;
        vector<int> ans;
        while(i < LEN(s1)){
            //cerr << 1 << " " << i << " " << j << "\n";
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            if(j == LEN(s2)){
                ans.pb(i-j+1);
                j = lps[j-1];
            }
            else if(i < LEN(s1) && s1[i] != s2[j]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        if(LEN(ans) == 0){
            cout << "Not Found\n";
        }else{
            cout << LEN(ans) << "\n";
            forn(i,0,LEN(ans)-1){
                cout << ans[i];
                if(i == LEN(ans) - 1){
                    cout << "\n";
                }else{
                    cout << " ";
                }
            }

        }
        cout << "\n";
    }


    return 0;
}
