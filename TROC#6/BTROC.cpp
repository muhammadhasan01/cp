#include<bits/stdc++.h>
using namespace std;

string s,t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    set<char> st;
    for(auto e:t)st.insert(e);
    if(st.size() > 1){
        puts("0");
        return 0;
    }
    int c1 = 0, c2 = 0;
    for(auto e:s){
        if(e == t[0]){
            c1++;
        }else{
            c2++;
        }
    }

    while(true){
        if(c1 <= 0){
            puts("0"); return 0;
        }
        if(c2 <= 0){
            cout << c1 - (int)t.size() + 1 << "\n";
            return 0;
        }
        c1 -= t.size() - 1;
        c2 --;
    }


    return 0;
}
