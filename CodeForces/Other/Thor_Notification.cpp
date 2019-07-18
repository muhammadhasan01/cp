#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int n,q;
int inv[N];
set<int> s[N];
set<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    int pos = 1;
    for(int i=1;i<=q;i++){
        int t,x; cin >> t >> x;
        if(t == 1){
            ans.insert(pos);
            s[x].insert(pos);
            inv[pos] = x;
            pos++;
        }else if(t == 2){
            while(!s[x].empty()){
                int e = *s[x].begin();
                s[x].erase(s[x].begin());
                ans.erase(ans.find(e));
            }
        }else if(t == 3){
            while(!ans.empty() && x >= *ans.begin()){
                int e = *ans.begin();
                int pos = inv[e];
                s[pos].erase(s[pos].find(e));
                ans.erase(ans.begin());
            }
        }
        cout << ans.size() << '\n';
    }


    return 0;
}
