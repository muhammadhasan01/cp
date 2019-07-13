#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define first fs
#define second sc
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Sum of digit

void change(string &x){
    ll k = 0;
    for(ll i=0;i<x.size();i++){
        k+=x[i]-'0';
    }
    ostringstream st;
    st << k;
    x = st.str();

}

ll SoD(string x){
    ll c = 0;
    while(x.size()>1){
        change(x);
        c++;
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a; cin >> a; cout << SoD(a) << "\n";
    return 0;
}
