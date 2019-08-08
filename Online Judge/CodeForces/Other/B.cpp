#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    int len = (int)str.size();
    int k;
    //cout << len << "\n";
    /*for(int i=1;i<=5;i++){
        int x;
        if(len%i == 0){
            x = len/i;
        }else{
            x = len/i+i-len%i;
        }
        cout << i << " " << x << "\n";
    }*/
    if(len <= 20){
        cout << 1 << " " << len << "\n";
        cout << str << "\n";
    }else if(20 < len && len <= 2*20){
        k = len%2;
        if(len%2 == 1){len++;}
        cout << 2 << " " << len/2 << "\n";
        len/=2;
        if(k == 1){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len+1)+"*" << "\n";}else
        if(k == 0){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len+1) << "\n";
        }
    }else if(2*20 < len && len <= 3*20){
        k = len%3;
        //cout << k << "\n";
        if(len%3!=0){len += 3-k;}
        cout << 3 << " " << len/3 << "\n";
        len/=3;
        if(k == 0){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len+1) << "\n";}
        else if(3-k == 1){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len+1)+"*" << "\n";
        }else if(3-k == 2){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len-1)+"*" << "\n";
            cout << str.substr(2*len-1,len+1)+"*" << "\n";
        }
    }else if(3*20 < len && len <= 4*20){
        k = len%4;
        //cout << k << "\n";
        if(len%4!=0){len += 4-k;}
        cout << 4 << " " << len/4 << "\n";
        len/=4;
        if(k == 0){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len) << "\n";
            cout << str.substr(3*len,len+1) << "\n";
        }
        else if(4-k == 1){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len) << "\n";
            cout << str.substr(3*len,len+1)+"*" << "\n";
        }else if(4-k == 2){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len-1)+"*" << "\n";
            cout << str.substr(3*len-1,len+1)+"*" << "\n";
        }else if(4-k == 3){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len-1)+"*" << "\n";
            cout << str.substr(2*len-1,len-1)+"*" << "\n";
            cout << str.substr(3*len-2,len+1)+"*" << "\n";
        }
    }else if(4*20 < len && len <= 5*20){
        k = len%5;
        //cout << k << "\n";
        if(len%5!=0){len += 5-k;}
        cout << 5 << " " << len/5 << "\n";
        len/=5;
        if(k == 0){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len) << "\n";
            cout << str.substr(3*len,len) << "\n";
            cout << str.substr(4*len,len+1) << "\n";
        }
        else if(5-k == 1){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len) << "\n";
            cout << str.substr(3*len,len) << "\n";
            cout << str.substr(4*len,len+1)+"*" << "\n";
        }else if(5-k == 2){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len) << "\n";
            cout << str.substr(3*len,len-1)+"*" << "\n";
            cout << str.substr(4*len-1,len+1)+"*" << "\n";
        }else if(5-k == 3){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len) << "\n";
            cout << str.substr(2*len,len-1)+"*" << "\n";
            cout << str.substr(3*len-1,len-1)+"*" << "\n";
            cout << str.substr(4*len-2,len+1)+"*" << "\n";
        }else if(5-k == 4){
            cout << str.substr(0,len) << "\n";
            cout << str.substr(len,len-1)+"*" << "\n";
            cout << str.substr(2*len-1,len-1)+"*" << "\n";
            cout << str.substr(3*len-2,len-1)+"*" << "\n";
            cout << str.substr(4*len-3,len+1)+"*" << "\n";
        }
    }

    return 0;
}
