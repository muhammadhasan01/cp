#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int q;
int n,k;
long long a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> k;
        vector<int> pl;
        int c = 0;
        for(int i=1;i<=n;i++){
            int x; cin >> x;
            if(x&1){
                if(c > 0){
                    pl.push_back(i-1);
                }
                c++;
            }
        }

        if(c > 0){
            pl.push_back(n);
        }

        int len = pl.size();
        if(k > len){
            cout << "NO" << '\n';
        }else if(k == len){
            cout << "YES" << '\n';
            for(int i=0;i<len;i++){
                cout << pl[i] << (i == len - 1 ? '\n':' ');
            }
        }else if(k < len){
            int dif = len - k;
            if(dif & 1){
                cout << "NO" << '\n';
            }else{
                cout << "YES" << '\n';
                for(int i=len-k;i<len;i++){
                    cout << pl[i] << (i == len-1 ? '\n':' ');
                }
            }
        }
    }

    return 0;
}
