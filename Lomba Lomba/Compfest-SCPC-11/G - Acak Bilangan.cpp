#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,k;
int a[N], b[N], cnt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=2*n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int maks = 0;
    for(int i=1;i<=N-5;i++){
        if(cnt[i] > maks){
            maks = cnt[i];
        }
    }
    cout << (maks - n <= k ? "Ya" : "Tidak") << '\n';

    return 0;
}
