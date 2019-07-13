#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    priority_queue<int> pq1,pq2;
    int res = 0;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        while(!pq2.empty() && res - pq2.top() <= m){
            int temp = pq2.top();
            pq2.pop();
            pq1.push(-temp);
            res -= temp;
        }
        while(res + x > m){
            int temp = pq1.top();
            pq1.pop();
            pq2.push(-temp);
            res -= temp;
        }
        cout << pq2.size() << " ";
        pq2.push(-x);
    }




    return 0;
}
