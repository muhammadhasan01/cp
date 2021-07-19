// author: faustaadp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define double long double
const ll NN = 2e5 + 5;
const ll mo = 998244353;
const ld eps = 1e-9; 
ll t, n;
ld x[NN];
ld y[NN];
ld R;
template<class T>
struct Point {
    T x, y;
    typedef Point P;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x−axis in interva l [−pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes d is t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<double> P;
bool circleIntersection(P a, P b, double r1, double r2,
pair<P, P>* out) {
P delta = b - a;
// assert(delta.x || delta.y || r1 != r2);
if(!(delta.x || delta.y || r1 != r2))return false;
if (!delta.x && !delta.y) return false;
double r = r1 + r2, d2 = delta.dist2();
double p = (d2 + r1*r1 - r2*r2) / (2.0 * d2);
double h2 = r1*r1 - p*p*d2;
if (d2 > r*r || h2 < 0) return false;
P mid = a + delta*p, per = delta.perp() * sqrtl(h2 / d2);
*out = {mid + per, mid - per};
return true;
}
ll cek(ld X, ld Y)
{
    for(ll i = 0; i <= n; i++)
    {
        ld Z = (x[i] - X) * (x[i] - X) + (y[i] - Y) * (y[i] - Y);
        if(Z - eps > R * R)
            return 0;
    }
    return 1;
}

int main()
{
    // // Point<double> p(1,1);
    // pair<P,P> p = circleTangents(P(0,3),P(3,0),2);
    // cout << p.fi.x << " " << p.fi.y << "\n";
    // cout << p.se.x << " " << p.se.y << "\n";
    freopen("robots.in", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll r1, r2;
        cin >> n >> r1 >> r2;
        R = r1 - r2;
        for(ll i = 1; i <= n; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            x[i] = x[i - 1] + ta;
            y[i] = y[i - 1] + tb;
        }
        ld jX = - 1, jY = -1;
        for(ll i = 1; i <= n; i++)
        {
            if(cek(x[i], y[i]))
            {
                jX = x[i];
                jY = y[i];
            }
            if(cek(x[i] / 2.0, y[i] / 2.0))
            {
                jX = x[i] / 2.0;
                jY = y[i] / 2.0;
            }
        }
        for(ll i = 1; i <= n; i++)
            for(ll j = i + 1; j <= n; j++)
            {
                Point<double> ai(x[i], y[i]);
                Point<double> aj(x[j], y[j]);
                pair<P, P> ak;
                bool B = circleIntersection(ai, aj, R, R, &ak);
                if(!B)continue;
                if(cek(ak.fi.x, ak.fi.y))
                {
                    jX = ak.fi.x;
                    jY = ak.fi.y;
                }
                if(cek(ak.se.x, ak.se.y))
                {
                    jX = ak.se.x;
                    jY = ak.se.y;
                }
            }
        jX = -jX;
        jY = -jY;
        cout << fixed << setprecision(9) << jX << " " << jY << "\n";
    }
}
    