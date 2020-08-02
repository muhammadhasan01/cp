#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const long double eps = 1e-9;
    
int tc;
long double a, b, c, x;
long double ca, cb, bc, ba;
    
long double G(long double pa, long double ha, long double hb) {
    long double lola = pa - ba;
    long double lolb = c + hb;
    long double ret = sqrtl(lola * lola + lolb * lolb); // from home to river
    long double da = ha - pa, db = c; 
    ret += sqrtl(da * da + db * db); // from river to some point
    return ret;
}
    
void solve() {
    scanf("%Lf %Lf %Lf %Lf", &a, &b, &c, &x);
    bc = b + c;
    long double res = 0;
    // To the river then to grandma's house
    long double l = 0, r = a;
    ba = 0;
    for (int i = 0; i < 60; i++) {
        long double p1 = l + (r - l) / 3.0;
        long double p2 = r - (r - l) / 3.0;
        if (G(p1, a, b) > G(p2, a, b)) {
            l = p1;
        } else {
            r = p2;
        }
    }
    res += G(r, a, b);
    long double apt = sqrtl(a * a + b * b); 
    x /= 100.0;
    long double y = 1 - x;
    res += apt * x; // x% to home
    ca = a * x, cb = b * y;
    // To river then to home
    l = ca, r = a;
    ba = ca;
    for (int i = 0; i < 60; i++) {
        long double p1 = l + (r - l) / 3.0;
        long double p2 = r - (r - l) / 3.0;
        if (G(p1, a, cb) > G(p2, a, cb)) {
            l = p1;
        } else {
            r = p2;
        }
    }
    res += G(r, a, cb);
    printf("%.9Lf\n", res);
}
    
int main() {
    scanf("%d", &tc);
    while (tc--) {
        solve();
    }
    
    return 0;
}