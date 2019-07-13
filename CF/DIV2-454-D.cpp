#include<bits/stdc++.h>
using namespace std;

string s,t;
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    vector<int> f(3,0);
    for(auto e:s)f[e - '0']++;

    n = s.length();
    m = t.length();

    if(n < m){
        cout << s << '\n';
    }else{
        vector<int> lps(m,0);
        for(int i=1;i<m;i++){
            int j = lps[i-1];
            while(j > 0 && t[i] != t[j])j = lps[j-1];
            if(t[i] == t[j])j++;
            lps[i] = j;
        }
        for(int i=0,j=0;i<n;i++,j++){
            if(j == m)j = lps[j-1];
            if(f[t[j] - '0'] > 0){
                f[t[j] - '0']--;
                cout << t[j];
            }else{
                f[!(t[j] - '0')]--;
                cout << !(t[j] - '0');
            }
        }
    }


    return 0;
}
