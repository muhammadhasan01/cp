// author : moondemon68
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<double,double>
#define LL double
#define INF 1e8
#define endl "\n"

using namespace std;

pii p[100115],c[100115],P0;

double triangleArea(pii a,pii b, pii c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

LL sqDist(pii a,pii b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool cmp(pii a,pii b) {
    double d=triangleArea(P0,a,b);
    if (d<0) return 0;
    return !(d==0&&sqDist(P0,a)>sqDist(P0,b));
}

bool normal(pii a,pii b) {
    if (a.x==b.x) {
        return a.y<b.y;
    } else {
        return a.x<b.x;
    }
}

bool same(pii a,pii b) {
    return a.x==b.x && a.y==b.y;
}

void nosame(int &np) {
    sort (p,p+np,normal);
    np=unique(p,p+np,same)-p;
}

void convexhull(int &np, int &nc) {
    int pos=0,j;
    for (int i=1;i<np;i++) {
        if (p[i].y<p[pos].y || (p[i].y==p[pos].y && p[i].x<p[pos].x)) pos=i;
    }
    swap(p[0],p[pos]);
    P0 = p[0];
    sort(&p[1],&p[np],cmp);
    for (int i=0;i<3;i++) {
        c[i]=p[i];
    }
    for (int i=j=3;i<np;i++) {
        while (triangleArea(c[j-2],c[j-1],p[i])<0) j--;
        c[j++]=p[i];
    }
    nc=j;
}



int main () {
    //clock_t start = clock();
    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        LL q;
        int np,nc;
        cin >> np >> q;
        for (int i=0;i<np;i++) cin >> p[i].x >> p[i].y;
        nosame(np);
        convexhull(np,nc);
        sort (c,c+nc,cmp);
        pii d[2*nc+5];
        for (int i=0;i<2*nc;i++) {
            d[i]=c[i%nc];
        }
        pii center = mp(0,0);
        LL minx=INT_MAX,miny=INT_MAX,mini=0;
        for (int i=0;i<nc;i++) {
            if (c[i].x<minx) {
                minx=c[i].x;
                miny = c[i].y;
                mini=i;
            } else if (c[i].x == minx && c[i].y<miny) {
                minx=c[i].x;
                miny = c[i].y;
                mini=i;
            }
            center = mp(center.x+c[i].x, center.y+c[i].y);
        }
        center = mp(center.x*(1.0/nc), center.y*(1.0/nc));
        cout << "Case " << t << endl;
        for (int i=mini;i<=mini+nc;i++) {
            cout << d[i].x << " " << d[i].y << endl;
        }
        c[nc]=c[0];
        while (q--) {
            LL ax,ay;
            cin >> ax >> ay;
            cout << ax << " " << ay << " is ";
            bool isInside = 1;
            pii pt = mp(ax,ay);
            for (int i=0;i<nc;i++) {
                pii u;
                u=mp(c[i+1].x-c[i].x,c[i+1].y-c[i].y);
                pii v1 = mp(center.x-c[i].x, center.y-c[i].y);
                pii v2 = mp(pt.x-c[i].x, pt.y-c[i].y);
                if (u.x*v2.y-u.y*v2.x==0) {
                    isInside = 1;
                    break;
                }
                if ((u.x*v1.y-u.y*v1.x) * (u.x*v2.y-u.y*v2.x)<0) {
                    isInside = 0;
                    break;
                }
            }
            if (isInside) cout << "unsafe!"; else cout << "safe!";
            cout << endl;
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
