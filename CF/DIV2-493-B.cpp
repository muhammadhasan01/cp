#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n,b;
int a[N],odd[N],even[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        odd[i] = odd[i-1];
        even[i] = even[i-1];
        if(a[i]&1)odd[i]++;
        else even[i]++;
    }

    if(odd[n] != even[n]){
        puts("0");
        return 0;
    }

    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n-1;i++){
        if(odd[i] == even[i]){
            pq.push(abs(a[i] - a[i+1]));
        }
    }

    while(!pq.empty()){
        int k = pq.top();
        pq.pop();
        if(b >= k)b -= k;
        else break;
        ans++;
    }

    cout << ans << "\n";



    return 0;
}
