#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 998244353;
long long n;
long long a[N];
vector<long long> dp[100];
long long pre[105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int j = 1;
        while(a[i] > 0){
            dp[j].push_back(a[i]%10);
            j++;
            a[i]/=10;
        }
    }

    pre[0] = 1;
    for(int i=1;i<=100;i++){
        pre[i] = pre[i-1] * 10;
        pre[i] %= M;
    }
    long long ans = 0;
    for(int i=1;i<=32;i++){
        for(auto e:dp[i]){
            ans += e * (n % M) * (pre[2*(i-1)] % M);
            ans %= M;
            ans += e * (n % M) * (pre[2*(i-1) + 1] % M);
            ans %= M;
        }
    }
    cout << (ans%M + M)%M << '\n';

    return 0;
}
