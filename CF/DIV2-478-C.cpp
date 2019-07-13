#include<bits/stdc++.h>
using namespace std;

int n,q;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    vector<long long> a(n),k(q);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<q;i++)cin >> k[i];

    vector<long long> pre(n,0);
    pre[0] = a[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + a[i];
    }

    long long sum = 0;
    for(int i=0;i<q;i++){
        sum += k[i];
        auto pos = lower_bound(pre.begin(),pre.end(),sum) - pre.begin();
        if(pos == n){
            cout << n << "\n";
            sum = 0;
        }else if(pre[pos] > sum){
            cout << n - pos << "\n";
        }else if(pre[pos] == sum){
            cout << (n - pos - 1 == 0 ? n : n - pos - 1) << "\n";
            sum = (n == pos + 1 ? 0 : sum);
        }
    }


    return 0;
}
