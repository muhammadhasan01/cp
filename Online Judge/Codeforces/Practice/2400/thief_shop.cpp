#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

const int K = 1e3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(K + 5, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    auto norm = [&](vector<int>& x) -> void {
        while (!x.empty()) {
            if (x.back() == 0) {
                x.pop_back();
                continue;
            }
            break;
        }
        for (int& val : x) {
            val = min(val, 1);
        }
    };
    norm(v);
    auto binpow = [&](vector<int> x, int y) -> vector<int> {
        vector<int> ret(1, 1);
        while (y > 0) {
            if (y % 2 == 1) {
                ret = multiply(ret, x);
                norm(ret);
            }
            y >>= 1;
            x = multiply(x, x);
            norm(x);
        }
        return ret;
    };
    vector<int> result = binpow(v, k);
    int len = result.size();
    for (int i = 0; i < len; i++) {
        if (result[i] == 0) {
            continue;
        }
        cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}