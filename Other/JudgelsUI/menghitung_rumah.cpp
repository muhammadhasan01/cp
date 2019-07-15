#include<bits/stdc++.h>
using namespace std;

struct st{
    int l,r,c,idx;
};

const int N = 1e5+5;
int n,m,q,block;
int a[N], ans[N];
st qr[N];

bool cmpr(st a, st b){
    if(a.l/block != b.l/block){
        return a.l/block < b.l/block;
    }
    return a.r < b.r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    block = sqrt(n+1);
    for(int i=1;i<=q;i++){
        cin >> qr[i].l >> qr[i].r >> qr[i].c;
        qr[i].idx = i;
    }
    sort(qr+1,qr+1+q,cmpr);
    int cl = 1, cr = 1;
    vector<int> res(m+1,0);
    for(int i=1;i<=n;i++){
        int l = qr[i].l, r = qr[i].r, c = qr[i].c;
        while(cl < l){
            res[a[cl]]--;
            cl++;
        }
        while(cl > l){
            res[a[cl-1]]++;
            cl--;
        }
        while(cr <= r){
            res[a[cr]]++;
            cr++;
        }
        while(cr > r + 1){
            res[a[cr-1]]--;
            cr--;
        }
        ans[qr[i].idx] = res[c];
    }
    for(int i=1;i<=q;i++){
        cout << ans[i] << '\n';
    }

    return 0;
}
