#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> f(n,0);
        vector<int> fg(n,0);
        for(int i=1;i<=n;i++){
            int x,y;
            cin >> x >> y;
            --x;
            f[x]++;
            if(y) fg[x]++;
        }
        vector<vector<int>> t(n+1);
        for(int i=0;i<n;i++){
            t[f[i]].push_back(fg[i]);
        }
        int sum = 0, fsum = 0;
        multiset<int> cur;
        for(int i=n;i>0;i--){
            for(auto e:t[i]) cur.insert(e);
            if(!cur.empty()){
                int tmp = *cur.rbegin();
                sum += i;
                fsum += min(i,tmp);
                cur.erase(cur.find(tmp));
            }
        }
        cout << sum << " " << fsum << "\n";
    }

}
