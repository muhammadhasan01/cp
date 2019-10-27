#include <bits/stdc++.h>
using namespace std;

struct st {
    int a, b, c;
};

const int N = 1e6 + 5;
int n;
string str;
st t[4*N];

st make(int x, int y, int z){
    st ret;
    ret.a = x, ret.b = y, ret.c = z;
    return ret;
}

st merge(st x, st y){
    int temp = min(x.b, y.c);
    int x1 = x.a + y.a + temp;
    int y1 = x.b + y.b - temp;
    int z1 = x.c + y.c - temp;
    return make(x1,y1,z1);
}

void build(int v, int s, int e){
    if (s == e) {
        if(str[s] == '(') {
            t[v] = make(0, 1, 0);
        } else {
            t[v] = make(0, 0, 1);
        }
    } else {
        int mid = (s + e) / 2;
        build(2 * v, s, mid);
        build(2 * v + 1, mid + 1, e);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

st query(int v, int s, int e, int l, int r){
    if (e < l || s > r) {
        return make(0, 0, 0);
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int mid = (s + e) / 2;
    return merge(query(2 * v, s, mid, l, r), query(2 * v + 1, mid + 1, e, l, r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    n = str.size();
    str = '#' + str;
    build(1, 1, n);
    cout << 2 * query(1, 1, n, 1, n).a << '\n';

    return 0;
}
