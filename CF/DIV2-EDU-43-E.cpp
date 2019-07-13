#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

const int N = 2e5+5;
int n,a,b;
long long dam = 0;

bool cmpr(pll a, pll b){
    return (a.first - a.second) > (b.first - b.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    vector<pll> p(n);
    long long times = (1<<a);
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(),p.end(),cmpr);

    pair<pll,int> last = {{0,0},0};

    int k = b;

    long long sum = 0;
    for(int i=0;i<n;i++){
        if(p[i].first > p[i].second && b > 0){
            sum += p[i].first;
            last.first = p[i];
            last.second = i;
            --b;
        }else{
            sum += p[i].second;
        }

        //cerr << p[i].first << " " << p[i].second <<  " " << b << "\n";
    }

    dam = sum;

    if(k == 0){
        cout << dam << '\n'; return 0;
    }

    for(int i=0;i<n;i++){
        long long res = p[i].first * times;
        //cerr << res << " and " << p[i].first << " => ";
        if(p[i].first > p[i].second && i <= last.second){
            //cerr << 1 << "\n";
            res += sum - p[i].first;
            dam = max(dam, res);
        }else if(res > p[i].second && b > 0){
            //cerr << 2 << "\n";
            res += sum - p[i].second;
            dam = max(dam, res);
        }else if(res > p[i].second && i > last.second){
            //cerr << 3 << "\n";
            res += sum - p[i].second - last.first.first + last.first.second;
            dam = max(dam, res);
        }
        //cerr << dam << " => " << res << "\n";

    }

    cout << dam << "\n";



    return 0;
}
