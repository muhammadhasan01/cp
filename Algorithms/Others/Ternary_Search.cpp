#include<bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/num_methods/ternary_search.html

double f(double k){
    return - k * k;
}

double ternary_search(double l, double r){
    double eps = 1e-9; // set the error limit here
    while(r - l > eps){
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        // evaluates the functions
        double f1 = f(m1);
        double f2 = f(m2);
        if(f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9) << ternary_search(-5, 5) << '\n';

    return 0;
}
