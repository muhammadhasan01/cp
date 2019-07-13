#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int n = s.size();
    if(n == 1){
        puts("No");
    }else if(n == 2){
        puts("No");
    }else{
        sort(s.begin(),s.end());
        s += '#';
        vector<int> v(n+5);
        int len = 0, cnt = 1;
        for(int i=0;i<n;i++){
            if(s[i] == s[i+1]){
                cnt++;
            }else{
                v[++len] = cnt;
                cnt = 1;
            }
        }
        if(len == 1 || len > 4){
            puts("No");
        }else if(len == 4){
            puts("Yes");
        }else if(len == 3){
            if(v[1] >= 2 || v[2] >= 2 || v[3] >= 2){
                puts("Yes");
            }else{
                puts("No");
            }
        }else if(len == 2){
            if(v[1] >= 2 && v[2] >= 2){
                puts("Yes");
            }else{
                puts("No");
            }
        }
    }


    return 0;
}
