#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n, k, d, a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    long double x = n, y = 0;
    for(int i=1;i<=n;i++)cin >> a[i];

    vector<pair<pair<int,int>,int>> test(k+2,{{0,0},0});
    int m = 0;

    set<int> inter;

    queue<int> q;
    for(int i=1;i<=k;i++){
        q.push(i);
    }

    for(int i=1;i<=n;i++){
        if(m < k){
            int pos = q.front();
            q.pop();
            test[pos].first.first = 0;
            test[pos].first.second = a[i];
            test[pos].second = i;
            m++;
        }

        if(m == k){
            while(m == k){
                d = round(100 * (y/x));
                for(int j=1;j<=k;j++){
                    test[j].first.first++;
                    if(test[j].first.first == test[j].first.second){
                        y++; m--;
                        q.push(j);
                    }
                }
                for(int j=1;j<=k;j++){
                    if(test[j].first.first == d){
                        inter.insert(test[j].second);
                    }
                }
            }
        }
    }

    while(m > 0){
        d = round(100 * (y/x));
        for(int j=1;j<=k;j++){
            if(test[j].first.first > test[j].first.second)continue;
            test[j].first.first++;
            if(test[j].first.first == test[j].first.second){
                y++; m--;
            }
        }
        for(int j=1;j<=k;j++){
            if(test[j].first.first > test[j].first.second)continue;
            if(test[j].first.first == d){
                inter.insert(test[j].second);
            }
        }
    }

    cout << inter.size() << '\n';


    return 0;
}
