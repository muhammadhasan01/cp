#include<iostream>
#include<map>
#include<bitset>
#include<set>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1000;
int n,p,r;
map<int,int> m;
set<string> ans;

void b1(bitset<N+2> &b){
    b.flip();
}

void b2(bitset<N+2> &b){
    for(int i=0;i<n;i+=2){
        if(b[i]==1)
            b[i] = 0;
        else
            b[i] = 1;
    }
}

void b3(bitset<N+2> &b){
    for(int i=1;i<n;i+=2){
        if(b[i] == 1)
            b[i] = 0;
        else
            b[i] = 1;
    }
}

void b4(bitset<N+2> &b){
    for(int i=0; i<n; i+=3){
        if(b[i] == 1)
            b[i] = 0;
        else
            b[i] = 1;
    }
}

void store(bitset<N+2> &b){
    string temp;
    for(int i=0;i<n;i++){
        if(b[i] == 0){
            temp += "0";
        }else{
            temp += "1";
        }
    }
    //cout << temp << "\n";
    ans.insert(temp);
}

void switcher(int k, bitset<N+2> &b){
    switch(k){
        case 1 :
            b1(b);
            break;
        case 2 :
            b2(b);
            break;
        case 3 :
            b3(b);
            break;
        case 4 :
            b4(b);
            break;
    }
}

void precal(bitset<N+2> b){
    for(int i=0;i<16;i++){
        bitset<N+2> c = b;
        int cnt = 0;
        for(int j=0;j<4;j++){
            if(i & 1<<j){
                cnt++;
                //cout << j+1 << "-";
                if(cnt > p)break;
                switcher(j+1,c);
            }
        }
        if(cnt == 0 || (p+cnt)%2 == 1){continue;/*cout << "Not Stored";*/}
        else{/*cout << "Stored";*/store(c);}
        //cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> p;
    int i = 1;
    while(cin >> r && r != -1){
        m[r] = 1;
    }
    while(cin >> r && r != -1){
        m[r] = -1;
    }
    //cout << m[3] << "\n";
    bitset<N+2> b;
    b.set();
    precal(b);
    if(p%2 == 0){
        string temp = "";
        for(int i=1;i<=n;i++){
            temp += "1";
        }
        ans.insert(temp);
    }
    //cout << "\n" << ans.size() << "*\n";
    for(set<string>::iterator i=ans.begin();i!=ans.end();i++){
        string cck = *i;
        bool y = true;
        for(int j=0;j<cck.size();j++){
            char x = cck[j];
            //cout << j+1 << " => " << m[j+1] << "\n";
            if(m[j+1] == 1 && x == '0'){
                y = false; break;
            }else if(m[j+1] == -1 && x == '1'){
                y = false; break;
            }
        }
        if(y){cout << *i << "\n";}
    }
    return 0;
}
