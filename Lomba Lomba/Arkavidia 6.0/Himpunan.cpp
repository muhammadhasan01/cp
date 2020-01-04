#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100000;
const LL LIMIT = 2e9;

int N;
LL K, H[MAXN+5];
priority_queue<LL, vector<LL>, greater<LL> > pq;
map<LL,int> last, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> H[i];
        pq.push(H[i]);
        last[H[i]] = i;
    }
    cin >> K;
    int order = 1;
    bool stop = false;
    while (!pq.empty() && pq.top() <= LIMIT && !stop){
        LL top = pq.top();
        pq.pop();
        ans[top] = order++;
        for (int i = 1; i <= N; ++i){
            if (i >= last[top]){
                last[H[i] * top] = i;
                if (top > LIMIT / H[i]) {
                    break;
                }
                else pq.push(H[i] * top);
            }
        }
    }
    cout << ans[K] << '\n';
    return 0;
}
