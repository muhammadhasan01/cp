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

    vector<string> s = {"hmm"};
    map<int, bool> mp;
    while (1) {
        string x; cin >> x;
        if (x[0] == '#') break;
        ++n;
        for (char c : x)
            mp[c - 'A'] = 1;
        s.emplace_back(x);
    }
    for(int i=1;i<n;i++){
        int k1 = s[i].size();
        int k2 = s[i+1].size();
        bool flag = true;
        for(int j=0;j<min(k1,k2);j++){
            if(s[i][j] != s[i+1][j]){
                char x = s[i][j];
                char y = s[i+1][j];
                g[x - 'A'].push_back(y - 'A');
                deg[y - 'A']++;
                flag = false;
                break;
            }
        }
        if(k1 > k2 && flag){
            assert(true);
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

        if (mp[k])
            ans.push_back(k);

        for(auto e : g[k]){
            if(--deg[e] == 0){
                q.push(e);
            }
        }
    }
    for (int x : ans)
        cout << char(x + int('A'));
    cout << '\n';

    return 0;
}