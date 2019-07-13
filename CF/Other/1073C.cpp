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

int n,a,b;
string s;

void update(pii &x, char c, int d){
    if(c == 'L'){
        x.ff -= d;
    }else if(c == 'R'){
        x.ff += d;
    }else if(c == 'U'){
        x.ss += d;
    }else if(c == 'D'){
        x.ss -= d;
    }
}

bool can(pii x, pii y, int len){
    int dist = abs(x.ff - y.ff) + abs(x.ss - y.ss);
    //cerr << dist << " * ";
    //cerr << (len >= dist) << "\n";
    if(dist%2 != len%2)return false;
    return len >= dist;
}

bool acc(int len){
    pii cor = {0,0};
    for(int i=len;i<n;i++)
        update(cor,s[i],1);

    //cerr << len << " => " << cor.ff << "," << cor.ss << "\n";

    int l = 0, r = len;
    while(1){
        if(can(cor,{a,b},len))return true;
        if(r == n)break;
        update(cor,s[l++],1);
        update(cor,s[r++],-1);
    }
    return false;
}

int solve(){
    if(abs(a) + abs(b) > n)
        return -1;
    if( (abs(a) + abs(b) + n) & 1 )
        return -1;
    int le = -1, ri = n;
    while(ri - le > 1){
        int mid = (le+ri)/2;
        //cerr << le << " " << ri << " => " << mid << "\n";
        if(acc(mid))ri = mid;
        else le = mid;
    }
    return ri;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> a >> b;
    cout << solve() << "\n";

    return 0;
}
