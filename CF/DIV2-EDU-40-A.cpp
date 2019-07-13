#include<bits/stdc++.h>
using namespace std;

int n;
string s;
stack<char> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> s;
    for(auto e:s){
        if(ans.empty()){
            ans.push(e);
        }else{
            if(ans.top() == 'R' && e == 'U'){
                ans.pop();
                ans.push('D');
            }else if(ans.top() == 'U' && e == 'R'){
                ans.pop();
                ans.push('D');
            }else{
                ans.push(e);
            }
        }
    }
    cout << ans.size() << '\n';

    return 0;
}
