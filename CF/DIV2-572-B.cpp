#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
long long a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int i = 2, j = n, k = 2, turn = 1;
    vector<int> b(n+1);
    b[1] = a[1];
    while(i <= j){
        //cerr << i << " => " << j << " => " << turn << " => " << k << " => " << a[k] << "\n";
        if(turn){
            b[i] = a[k];
            i++, k++;
        }else{
            b[j] = a[k];
            j--, k++;
        }
        turn = 1 - turn;
    }
    //for(int i=1;i<=n;i++)cout << b[i] << " ";cout<<'\n';
    bool ok = true;
    for(int i=1;i<=n-2;i++){
        ok &= (b[i] + b[i+2] > b[i+1]);
    }
    ok &= (b[n-1] + b[1] > b[n]);
    ok &= (b[n] + b[2] > b[1]);

    if(!ok){
        cout << "NO" << "\n";
    }else{
        cout << "YES" << '\n';
        for(int i=1;i<=n;i++)cout << b[i] << (i == n ? '\n' : ' ');
    }


    return 0;
}
