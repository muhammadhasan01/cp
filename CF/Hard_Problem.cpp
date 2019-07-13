#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
string s[N], rs[N];
long long c[N];
pair<long long, bool> dp[N][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    for(int i=1;i<=n;i++){
        cin >> s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(),rs[i].end());
    }
    dp[1][1] = {0,true};
    dp[1][2] = {c[1],true};
    for(int i=2;i<=n;i++){
        bool one = (s[i] >= s[i-1]);
        bool two = (s[i] >= rs[i-1]);
        bool three = (rs[i] >= s[i-1]);
        bool four = (rs[i] >= rs[i-1]);
        if(one && two){
            if(dp[i-1][1].second && dp[i-1][2].second){
                dp[i][1].first = min(dp[i-1][1].first, dp[i-1][2].first);
                dp[i][1].second = true;
            }else if(dp[i-1][1].second){
                dp[i][1].first = dp[i-1][1].first;
                dp[i][1].second = true;
            }else if(dp[i-1][2].second){
                dp[i][1].first = dp[i-1][2].first;
                dp[i][1].second = true;
            }else{
                dp[i][1].first = -1;
                dp[i][1].second = false;
            }
        }else if(one && dp[i-1][1].second){
            dp[i][1].first = dp[i-1][1].first;
            dp[i][1].second = true;
        }else if(two && dp[i-1][2].second){
            dp[i][1].first = dp[i-1][2].first;
            dp[i][1].second = true;
        }else{
            dp[i][1].first = -1;
            dp[i][1].second = false;
        }

        if(three && four){
            if(dp[i-1][1].second && dp[i-1][2].second){
                dp[i][2].first = c[i] + min(dp[i-1][1].first, dp[i-1][2].first);
                dp[i][2].second = true;
            }else if(dp[i-1][1].second){
                dp[i][2].first = c[i] + dp[i-1][1].first;
                dp[i][2].second = true;
            }else if(dp[i-1][2].second){
                dp[i][2].first = c[i] + dp[i-1][2].first;
                dp[i][2].second = true;
            }else{
                dp[i][2].first = -1;
                dp[i][2].second = false;
            }
        }else if(three && dp[i-1][1].second){
            dp[i][2].first = c[i] + dp[i-1][1].first;
            dp[i][2].second = true;
        }else if(four && dp[i-1][2].second){
            dp[i][2].first = c[i] + dp[i-1][2].first;
            dp[i][2].second = true;
        }else{
            dp[i][2].first = -1;
            dp[i][2].second = false;
        }
    }

    if(dp[n][1].second && dp[n][2].second){
        cout << min(dp[n][1].first,dp[n][2].first) << "\n";
    }else if(dp[n][1].second){
        cout << dp[n][1].first << "\n";
    }else if(dp[n][2].second){
        cout << dp[n][2].first << "\n";
    }else{
        cout << -1 << "\n";
    }

    return 0;
}
