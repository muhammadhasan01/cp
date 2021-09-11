const int MAX = 2e5 + 5;
const int p1 = 37;
const int mod1 = 1e9 + 7;
const int p2 = 31;
const int mod2 = 1e9 + 9;

long long pwr1[MAX + 7], pwr2[MAX + 7];
long long ipwr1[MAX + 7], ipwr2[MAX + 7];

long long modpow(long long x, long long y, long long m) {
    long long ret = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ret = (ret * x) % m;
        }
        y >>= 1;
        x = (x * x) % m;
    }
    return ret;
}

void precalc() {
    long long pw1 = 1, pw2 = 1;
    for (int i = 0; i < MAX; i++) {
        pwr1[i] = pw1;
        pwr2[i] = pw2;
        pw1 = (pw1 * p1) % mod1;
        pw2 = (pw2 * p2) % mod2;
        ipwr1[i] = modpow(pwr1[i], mod1 - 2, mod1);
        ipwr2[i] = modpow(pwr2[i], mod2 - 2, mod2);   
    }
}

long long norm(long long x, long long m) {
    return (x % m + m) % m;  
};

struct dhash {
    pair<long long, long long> p;
    dhash() {
        p = make_pair(0LL, 0LL);
    }
    
    dhash(long long x, long long y) {
        p = make_pair(norm(x, mod1), y);
    }

    dhash operator+(dhash y) {
        return dhash(norm(this->p.first + y.p.first, mod1), norm(this->p.second + y.p.second, mod2));
    }

    dhash operator+(long long x) {
        return *this + dhash(x);
    }

    dhash operator-(dhash y) {
        return dhash(norm(this->p.first - y.p.first, mod1), norm(this->p.second - y.p.second, mod2));
    }

    dhash operator-(long long x) {
        return *this - dhash(x);
    }

    dhash operator*(long long x) {
        auto cur = this->p;
        cur.first = (cur.first * x) % mod1;
        cur.second = (cur.second * x) % mod2;
        return dhash(cur.first, cur.second);
    }
};