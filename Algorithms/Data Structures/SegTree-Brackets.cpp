#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+3;
pair<int,int> t[4*N];
string str;

pair<int,int> merge(pair<int,int> a, pair<int,int> b){
    pair<int,int> res;
    int temp = min(a.first,b.second);
    res.first = a.first + b.first - temp;
    res.second = a.second + b.second - temp;
    return res;
}

void build(int v, int s, int e){
    if(s == e){
        t[v].first = (str[s] == '(');
        t[v].second = (str[s] == ')');
    }else{
        int mid = (s+e)>>1;
        build(2*v,s,mid);
        build(2*v+1,mid+1,e);
        t[v] = merge(t[2*v],t[2*v+1]);
    }
}

void update(int v, int s, int e, int pos){
    if(s == e){
        if(str[s] == '('){
            str[s] = ')';
        }else{
            str[s] = '(';
        }
        t[v].first = (str[s] == '(');
        t[v].second = (str[s] == ')');
    }else{
        int mid = (s+e)>>1;
        if(pos <= mid){
            update(2*v,s,mid,pos);
        }else{
            update(2*v+1,mid+1,e,pos);
        }
        t[v] = merge(t[2*v],t[2*v+1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        cin >> str;
        int n = (int)str.size();
        build(1,0,n-1);
        int q;
        while(1==1){
            cin >> q;
            if(q == 1){
                int pos; cin >> pos;
                update(1,0,n-1,pos);
            }else if(q == 0){
                cout << (t[1].first == 0 && t[1].second == 0 ? "Y":"T");
            }else{
                break;
            }
        }
        cout << '\n';
    }


    return 0;
}
