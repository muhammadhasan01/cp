#include<bits/stdc++.h>
using namespace std;

int hh,mm;
long double h,d,c,n;

long long ceil(long long a, long long b){
    return (a+b-1)/b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> hh >> mm >> h >> d >> c >> n;
    cout << fixed << setprecision(9);
    int minutes = 60*hh + mm;
    int req = 20 * 60;
    long double ans = 1e18;
    if(minutes >= req){
        c *= 0.8;
        ans = min(ans,(long double)ceil(h,n) * c);
    }else{
        //cerr << "ok" << '\n';
        while(minutes < req){
            ans = min(ans, (long double)ceil(h,n) * c);
            //cerr << ceil(h,n)*c << " => ";
            //cerr << minutes << "\n";
            h += d;
            minutes++;
        }
        //cerr << h/n << " fun " << '\n';
        c *= 0.8;// cerr << c << "\n";
        //cerr << ceil(h,n)*c << " => ";
        //cerr << minutes << "\n";
        ans = min(ans, (long double)ceil(h,n) * c);
    }
    cout << ans << "\n";

    return 0;
}
