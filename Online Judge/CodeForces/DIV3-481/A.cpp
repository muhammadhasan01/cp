#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n;
int a[N];
bitset<N> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    deque<int> ans;
    for(int i=n;i>=1;i--){
        if(!vis[a[i]]){
            vis[a[i]] = 1;
            ans.push_front(a[i]);
        }
    }
    cout << ans.size() << '\n';
    for(auto e:ans)cout << e << " ";

    return 0;
}
