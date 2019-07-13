#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<long long, long long>, int> plli;

const int N = 3e5+5;
int n;
plli p[N];

bool cmpr(plli a, plli b){
    if(a.first.first == b.first.first){
        return a.first.second > b.first.second;
    }
    return a.first.first < b.first.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }

    sort(p+1,p+1+n,cmpr);

    int x = -1, y = -1;
    plli last = p[1];
    for(int i=2;i<=n;i++){
        if(p[i].first.first >= last.first.first && p[i].first.second <= last.first.second){
            x = p[i].second;
            y = last.second;
        }else{
            last = p[i];
        }
    }

    cout << x << " " << y << "\n";




    return 0;
}
