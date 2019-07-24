#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int n,k;
long long a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long ans = a[n] - a[1];
    priority_queue<int> pq;
    for(int i=n;i>=2;i--){
        pq.push(a[i] - a[i-1]);
    }

    int cnt = 0;
    while(!pq.empty() && cnt < k-1){
        ans -= pq.top();
        pq.pop();
        cnt++;
    }

    cout << ans << '\n';

    return 0;
}
