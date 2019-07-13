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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

string s, hasil = "";

string f(string x, int &pos){
    string tmp = "";
    forn(i,pos,sz(x)-1){
        if(x[i] == '('){
            pos = i+1;
            string k = f(x,pos);
            tmp += k;
            i = pos;
        }else if(x[i] == ')'){
            reverse(all(tmp));
            pos = i;
            return tmp;
        }else{
            tmp += x[i];
        }
    }
    pos = sz(x)-1;
    return "(" + tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = sz(s)-1;
    forn(i,0,n){
        if(s[i] == '%' && i+2 <= n && s[i+1] == '2' && s[i+2] == '0'){
            hasil += " ";
            i+=2;
        }else if(s[i] == '%' && i+2 <= n && s[i+1] == '2' && s[i+2] == '8'){
            hasil += "(";
            i+=2;
        }else if(s[i] == '%' && i+2 <= n && s[i+1] == '2' && s[i+2] == '9'){
            hasil += ")";
            i+=2;
        }else if(s[i] == '%' && i+2 <= n && s[i+1] == '2' && s[i+2] == 'C'){
            hasil += ",";
            i+=2;
        }else if(s[i] == '%' && i+2 <= n && s[i+1] == '2' && s[i+2] == '2'){
            hasil += "“";
            i+=2;
        }else if(s[i] == '%' && i+2 <= n && s[i+1] == '2' && s[i+2] == '7'){
            hasil += "‘";
            i+=2;
        }else if(s[i] == '%' && i+2 <= n && s[i+1] == '2' && s[i+2] == '1'){
            hasil += "!";
            i+=2;
        }else if(s[i] == '%' && i+2 <= n && s[i+1] == '3' && s[i+2] == 'F'){
            hasil += "?";
            i+=2;
        }else{
            hasil += s[i];
        }
    }

    string ans = "";
    forn(i,0,sz(hasil)-1){
        if(hasil[i] == '('){
            int pos = i+1;
            string temp = f(hasil,pos);
            ans += temp;
            i = pos;
        }else{
            ans += hasil[i];
        }
    }

    cout << ans << "\n";

    return 0;
}
