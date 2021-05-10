struct Line  {
    long long m, c;
    Line() {}
    Line(long long _m, long long _c) : m(_m), c(_c) {}

    long double intersectX(const Line& other) const {
        return (long double) * (other.c - c) / (m - other.m);
    };

    long long get(long long x) {
        return m * x + c;
    }

    // intersect(p1, p3) <= intersect(p1, p2)
    friend inline bool overlap(const Line &p1, const Line &p2, const Line &p3) {
        return (p3.c - p1.c) * (p1.m - p2.m) <= (p1.m - p3.m) * (p2.c - p1.c);
    }
};