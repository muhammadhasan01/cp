#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }

    vector<int> pl(n+3);
    int len = 1;
    pl[1] = 1;

    int cur = a[1];

    for(int i=2;i<=n;i++){
        if(a[i]*2 <= a[1]){
            pl[++len] = i;
            cur += a[i];
        }
    }

    if(2 * cur <= sum){
        puts("0");
    }else{
        cout << len << '\n';
        for(int i=1;i<=len;i++)cout << pl[i] << (i == len ? '\n' : ' ');
    }

    return 0;
}
