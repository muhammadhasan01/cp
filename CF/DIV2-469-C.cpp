#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int n = s.size();
    set<int> p1,p2;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            p1.insert(i+1);
        }else{
            p2.insert(i+1);
        }
    }

    vector<vector<int>> ans;
    while(!p1.empty()){
        int e = *p1.begin();
        vector<int> temp;
        temp.push_back(e);
        if(!p2.empty()){
            if(*p2.begin() < e){
                puts("-1");
                return 0;
            }
            auto it = p2.lower_bound(e);
            if(it != p2.end()){
                while(it != p2.end()){
                    temp.push_back(*it);
                    auto it2 = p1.lower_bound(*it);
                    if(it2 == p1.end()){
                        puts("-1");
                        return 0;
                    }else{
                        temp.push_back(*it2);
                        it = p2.lower_bound(*it2);
                    }
                }
                ans.push_back(temp);
                for(int i=0;i<temp.size();i++){
                    if(i & 1){
                        p2.erase(p2.find(temp[i]));
                    }else{
                        p1.erase(p1.find(temp[i]));
                    }
                }
            }
        }else{
            ans.push_back(temp);
            p1.erase(p1.begin());
        }
    }

    if(ans.empty()){
        puts("-1");
        return 0;
    }else{
        int sum = 0;
        for(auto ve:ans)sum += (int)ve.size();
        if(sum != n){
            puts("-1");
            return 0;
        }
    }

    cout << ans.size() << "\n";
    for(auto ve:ans){
        int len = ve.size();
        cout << len << " ";
        for(int i=0;i<len;i++){
            cout << ve[i] << (i == len - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
