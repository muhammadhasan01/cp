#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
pair<long long,long long> p[N];

pair<long long,long long> comp(pair<long long,long long> a, pair<long long,long long> b){
    return {b.first - a.first, b.second - a.second};
}

long long cross(pair<long long,long long> a, pair<long long,long long> b){
    return (a.first * b.second - b.first * a.second);
}

bool check(pair<long long,long long> a, pair<long long,long long> b){
    pair<long long,long long> res = comp(b,a);
    vector<bool> v(n+3,false);
    for(int i=1;i<=n;i++){
        pair<long long,long long> temp = comp(p[i],a);
        if(cross(res,temp)!=0)v[i] = true;
    }
    int p1 = -1, p2 = -1;
    for(int i=1;i<=n;i++){
        if(v[i] && p1 == -1){
            p1 = i;
        }else if(v[i] && p2 == -1){
            p2 = i;
        }
    }
    if(p2 == -1)return true;
    res = comp(p[p2],p[p1]);
    for(int i=1;i<=n;i++){
        if(v[i]){
            pair<long long,long long> temp = comp(p[i],p[p1]);
            if(cross(res,temp) != 0)return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i].first >> p[i].second;
    }
    if(n <= 2){
        puts("YES");
        return 0;
    }

    puts(check(p[1],p[2]) || check(p[1],p[3]) || check(p[2],p[3]) ? "YES" : "NO");

    return 0;
}
