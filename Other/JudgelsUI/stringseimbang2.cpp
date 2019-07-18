#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int n;
char a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    stack<pair<char,int>> st;
    long long ans = 0;
    vector<long long> dp(n+3);
    for(int i=1;i<=n;i++){
        if(st.empty() && a[i] == ')'){
            continue;
        }else if(st.empty() && a[i] == '('){
            st.push({a[i],i});
        }else if(st.top().first == '(' && a[i] == ')'){
            int pos = st.top().second;
            st.pop();
            dp[i] = dp[pos - 1] + 1;
            ans += dp[i];
        }else{
            st.push({a[i],i});
        }
    }
    cout << ans << '\n';

    return 0;
}
