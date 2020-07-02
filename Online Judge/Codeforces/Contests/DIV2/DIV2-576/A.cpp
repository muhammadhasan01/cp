#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,x,y;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        bool ok1 = true, ok2 = true;
        if(x > 0){
            for(int k=i-1;k>=max(1,i-x);k--){
                ok1 &= (a[i] < a[k]);
            }
        }
        if(y > 0){
            for(int k=i+1;k<=min(n,i+y);k++){
                ok2 &= (a[i] < a[k]);
            }
        }
        if(ok1 && ok2){
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
