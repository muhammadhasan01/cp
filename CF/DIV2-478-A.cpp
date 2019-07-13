#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    set<set<char>> s;
    for(int i=1;i<=n;i++){
        string ss;
        cin >> ss;
        set<char> st;
        for(auto e:ss){
            st.insert(e);
        }
        s.insert(st);
    }

    cout << s.size() << "\n";

    return 0;
}
