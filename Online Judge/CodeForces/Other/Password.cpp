#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();
    vector<int> lps(n+3,0);
    for(int i=1,j=0;i<n;i++){
        while(j > 0 && s[j] != s[i])j = lps[j-1];
        if(s[j] == s[i])j++;
        lps[i] = j;
    }

    reverse(s.begin(),s.end());

    vector<int> lps2(n+3,0);
    for(int i=1,j=0;i<n;i++){
        while(j > 0 && s[j] != s[i])j = lps2[j-1];
        if(s[j] == s[i])j++;
        lps2[i] = j;
    }

    reverse(s.begin(),s.end());

    int len = 0;
    for(int i=1;i<n-1;i++){
        if(lps[i] > 0 && lps[i] == lps2[n - (i - lps[i] + 1) - 1]){
            len = max(len,lps[i]);
        }
    }
    cout << (len > 0 ? s.substr(0,len) : "Just a legend") << "\n";

    return 0;
}
