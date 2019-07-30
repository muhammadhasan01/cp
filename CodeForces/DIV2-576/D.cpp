#include<bits/stdc++.h>
using namespace std;

struct st{
    int tc,p,x;
};

const int N = 2e5+5;
int n,q;
int a[N];
st qr[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cin >> q;
    for(int i=1;i<=q;i++){
        cin >> qr[i].tc;
        if(qr[i].tc == 1){
            cin >> qr[i].p >> qr[i].x;
        }else{
            cin >> qr[i].x;
            qr[i].p = -1;
        }
    }

    vector<int> pl(n+3,0);
    vector<int> suf(q+3,-1);
    for(int i=q;i>=0;i--){
        suf[i] = suf[i + 1];
        if(qr[i].tc == 1){
            int k = qr[i].p;
            if(pl[k] < i){
                pl[k] = i;
                a[k] = qr[i].x;
            }
        }else if(qr[i].tc == 2){
            suf[i] = max(suf[i], qr[i].x);
        }
    }

    for(int i=1;i<=n;i++){
        cout << max(a[i], suf[pl[i]]) << (i == n ? '\n' : ' ');
    }

    return 0;
}
