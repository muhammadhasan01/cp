#include<bits/stdc++.h>
using namespace std;

string x,y;

bool check(int l1, int r1, int l2, int r2){
    bool ok = true;
    for(int i=l1, j=l2 ; i <= r1 && j <= r2; i++, j++){
        ok &= x[i] == y[j];
        if(!ok)break;
    }
    if(ok){
        return true;
    }else if((r1 - l1 + 1)&1 || (r1-l1 + 1) != (r2-l2 + 1)){
        return false;
    }else{
        int m1 = (l1 + r1)>>1;
        int m2 = (l2 + r2)>>1;
        ok = check(l1,m1,l2,m2) && check(m1+1,r1,m2+1,r2);
        if(ok){
            return true;
        }else{
            return check(l1,m1,m2+1,r2) && check(m1+1,r1,l2,m2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;
    int n = x.size();
    cout << (check(0,n-1,0,n-1) ? "YES" : "NO") << '\n';

    return 0;
}
