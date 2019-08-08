#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
long double a[N];

long double f(long double x){
    long double max_sum = 0, max_far = -1e18;
    long double min_sum = 0, min_far = 1e18;
    for(int i=1;i<=n;i++){
        max_sum += (a[i] - x);
        min_sum += (a[i] - x);
        if(max_sum > max_far){
            max_far = max_sum;
        }
        if(min_sum < min_far){
            min_far = min_sum;
        }
        if(max_sum < 0){
            max_sum = 0;
        }
        if(min_sum > 0){
            min_sum = 0;
        }
    }
    return max(max_far, -min_far);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    long double l = -1e5, r = 1e5, eps = 1e-12;
    while(r - l > eps){
        long double m1 = l + (r - l)/3;
        long double m2 = r - (r - l)/3;
        if(f(m1) > f(m2)){
            l = m1;
        }else{
            r = m2;
        }
    }
    cout << fixed << setprecision(9) << f(l) << '\n';

    return 0;
}
