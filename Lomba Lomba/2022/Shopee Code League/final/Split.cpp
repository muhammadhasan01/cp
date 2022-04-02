// Author: Micchon
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>

const int MOD = 1000000007;
//const int MOD = 998244353;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m; cin >> n >> m;
    map<string,int> nama;
    forn(i,n){
        string tmp; cin >> tmp;
        nama[tmp] = i;
    }

    vi hutang(n,0);

    forn(t,m){
        int b; cin >> b;
        string yg_bayar; cin >> yg_bayar;
        int bayar = nama[yg_bayar];

        forn(t2,b){
            int harga; cin >> harga;
            hutang[bayar] -= harga;
            int jmlNumpang; cin >> jmlNumpang;
            harga /= jmlNumpang;
            forn(i,jmlNumpang){
                string yg_dibayarin; cin >> yg_dibayarin;
                hutang[nama[yg_dibayarin]] += harga;
            }
        }
    }

    int total_uang = 0;
    forn(i,n) total_uang += max(hutang[i] , 0LL);
    cout << total_uang << ' ';

    vector<int> pos,neg;
    forn(i,n){
        if(hutang[i] > 0) pos.push_back(hutang[i]);
        else if(hutang[i] < 0) neg.push_back(-hutang[i]);
    }

    if(pos.size() > neg.size()){
        swap(pos,neg);
    }
    if(pos.size() == 0){
        cout << "0\n";
    }
    else if(pos.size() == 1){
        cout << neg.size() << '\n';
    }
    else if(pos.size() == 2){
        //cari 1 yg match
        bool ada = 0;
        for(int x : pos) for(int y : neg) ada |= (x == y);
        if(ada) cout << neg.size() << '\n'; else cout << neg.size() + 1 << '\n';
    }
    else{
        //help
        // kalau ada 3" sama -> 3
        // kalau 1 sama -> 4?
        int sama = 0;
        vi vis1(pos.size(),0); vi vis2(neg.size(),0);
        for(int i=0;i<pos.size();i++){
            for(int j=0;j<neg.size();j++){
                if(vis1[i] || vis2[j]) continue;
                if(pos[i] == neg[j]){
                    vis1[i] = vis2[j] = 1;
                    sama++;
                }
            }
        }

        if(sama == 3) cout << "3\n";
        else if(sama == 1) cout << "4\n";
        else cout << "5\n";
    }
    return 0;
}


