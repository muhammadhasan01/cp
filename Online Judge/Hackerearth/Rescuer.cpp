#include<bits/stdc++.h>
using namespace std;

int tc;
const long double eps = 1e-9;
long double x1,x2,y_1,y_2,v1,v2;

long double f(long double x){
    return sqrt(abs(x - x1) * abs(x - x1) + y_1 * y_1)/v1 + sqrt(abs(x - x2) * abs(x - x2) + y_2 * y_2)/v2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> x1 >> y_1 >> x2 >> y_2 >> v1 >> v2;
        long double l = min(x1,x2), r = max(x1,x2);
        while(r - l > eps){
            long double m1 = l + (r - l)/3, m2 = r - (r - l)/3;
            if(f(m1) > f(m2)){
                l = m1;
            }else{
                r = m2;
            }
        }
        cout << fixed << setprecision(5) << f(l) << "\n";
    }

    return 0;
}
