#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
vector<int> g[30];
string s[N];
int deg[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    for(int i=1;i<n;i++){
        int k1 = s[i].size();
        int k2 = s[i+1].size();
        bool flag = true;
        for(int j=0;j<min(k1,k2);j++){
            if(s[i][j] != s[i+1][j]){
                char x = s[i][j];
                char y = s[i+1][j];
                g[x - 'a'].push_back(y - 'a');
                deg[y - 'a']++;
                flag = false;
                break;
            }
        }
        if(k1 > k2 && flag){
            puts("Impossible");
            return 0;
        }
    }

    queue<int> q;
    for(int i=0;i<26;i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int k = q.front();
        q.pop();

        ans.push_back(k);

        for(auto e : g[k]){
            if(--deg[e] == 0){
                q.push(e);
            }
        }
    }

    vector<int> cnt(30);
    for(auto e:ans)cnt[e]++;
    for(int i=0;i<26;i++){
        if(cnt[i] != 1){
            puts("Impossible");
            return 0;
        }
    }
    for(int i=0;i<26;i++){
        cout << char(ans[i] + 'a');
    }
    cout << '\n';

    return 0;
}
