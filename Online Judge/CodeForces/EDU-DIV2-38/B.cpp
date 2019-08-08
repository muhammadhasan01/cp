#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 1e6;
int n;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int t3 = 0;
    for(int i=1;i<=n;i++){
        if(abs(a[i] - 1) < abs(M - a[i])){
            t3 = max(t3, abs(a[i] - 1));
        }else{
            t3 = max(t3, abs(M - a[i]));
        }
    }
    cout << t3 << '\n';

    return 0;
}
