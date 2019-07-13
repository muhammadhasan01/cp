#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;
    queue<string> q;
    set<string> st;
    q.push(s);
    st.insert(s);
    int ans = 0;
    while(!q.empty() && (int)st.size() < k){
        string tmp = q.front();
        q.pop();
        for(int i=0;i<(int)tmp.size();i++){
            string ttmp = tmp;
            ttmp.erase(i,1);
            if(!st.count(ttmp) && (int)st.size() + 1 <= k){
                q.push(ttmp);
                st.insert(ttmp);
                ans += n - ttmp.size();
            }
        }
    }
    cout << ((int)st.size() < k ? -1 : ans) << '\n';

    return 0;
}
