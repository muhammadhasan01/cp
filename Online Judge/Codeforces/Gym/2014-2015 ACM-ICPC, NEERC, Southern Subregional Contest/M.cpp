// author: Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 60;

string s[N];
int n;
stack <pair<pii, int>> qu[26]; // pos, dep
vector <pair<pair<pii, pii>, char>> ans; // pos-shadower, pos-shadowed

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    for (int i=1;i<=n;i++){
        string temp;
        getline(cin, temp);
        s[i] = " " + temp;
    }

    int dep = 0;
    for (int i=1;i<=n;i++){
        int len = s[i].length();
        for (int j=1;j<len;j++){
            if (s[i][j] == ' ') continue;
            if (s[i][j] == '{'){
                dep++;
                continue;
            } else if (s[i][j] == '}'){
                for (int i=0;i<26;i++){
                    while (!qu[i].empty() && qu[i].top().se == dep) qu[i].pop();
                }
                dep--;
                continue;
            }
            int dig = s[i][j] - 'a';
            pii curpos = mp(i, j);
            if (!qu[dig].empty()){
                auto temp = qu[dig].top();
                ans.pb(mp(mp(curpos, temp.fi), s[i][j]));
            } 
            qu[dig].push(mp(curpos, dep));
        }
    }
    for (auto x : ans){
        pii er = x.fi.fi;
        pii ed = x.fi.se;
        char ss = x.se;
        cout << er.fi << ":" << er.se << ": warning: shadowed declaration of " << ss << ", the shadowed position is " << ed.fi << ":" << ed.se << el;
    }

    return 0;
}