#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

template <class T>
int sgn(T x)
{
    return (x > 0) - (x < 0);
}
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0)
        : x(x)
        , y(y)
    {
    }
    bool operator<(P p) const
    {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const
    {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const
    {
        return P(x + p.x, y + p.y);
    }
    P operator-(P p) const
    {
        return P(x - p.x, y - p.y);
    }
    P operator*(T d) const
    {
        return P(x * d, y * d);
    }
    P operator/(T d) const
    {
        return P(x / d, y / d);
    }
    T dot(P p) const
    {
        return x * p.x + y * p.y;
    }
    T cross(P p) const
    {
        return x * p.y - y * p.x;
    }
    T cross(P a, P b) const
    {
        return (a - *this).cross(b - *this);
    }
    T manhattan(P p) const
    {
        return abs(x - p.x) + abs(y - p.y);
    }
    T dist2() const
    {
        return x * x + y * y;
    }
    double dist() const
    {
        return sqrt((double)dist2());
    }
    // angle to x-axis in interval [-pi, pi]
    double angle() const
    {
        return atan2(y, x);
    }
    P unit() const
    {
        return *this / dist();
    } // makes dist()=1
    P perp() const
    {
        return P(-y, x);
    } // rotates +90 degrees
    P normal() const
    {
        return perp().unit();
    }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const
    {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p)
    {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef long long T;
typedef Point<T> P;
const T INF = numeric_limits<T>::max();

bool on_x(const P& a, const P& b)
{
    return a.x < b.x;
}
bool on_y(const P& a, const P& b)
{
    return a.y < b.y;
}

struct Node {
    P pt; // if this is a leaf, the single point in it
    T x0 = INF, x1 = -INF, y0 = INF, y1 = -INF; // bounds
    Node *first = 0, *second = 0;

    T distance(const P& p)
    {
        T x = (p.x < x0 ? x0 : p.x > x1 ? x1 : p.x);
        T y = (p.y < y0 ? y0 : p.y > y1 ? y1 : p.y);
        return (P(x, y)).manhattan(p);
    }

    Node(vector<P>&& vp)
        : pt(vp[0])
    {
        for (P p : vp) {
            x0 = min(x0, p.x);
            x1 = max(x1, p.x);
            y0 = min(y0, p.y);
            y1 = max(y1, p.y);
        }
        if (vp.size() > 1) {
            // split on x if width >= height (not ideal...)
            sort(all(vp), x1 - x0 >= y1 - y0 ? on_x : on_y);
            // divide by taking half the array for each child (not
            // best performance with many duplicates in the middle)
            int half = sz(vp) / 2;
            first = new Node({ vp.begin(), vp.begin() + half });
            second = new Node({ vp.begin() + half, vp.end() });
        }
    }
};

struct KDTree {
    Node* root;
    KDTree(const vector<P>& vp)
        : root(new Node({ all(vp) }))
    {
    }

    pair<T, P> search(Node* node, const P& p)
    {
        if (!node->first) {
            // uncomment if we should not find the point itself:
            // if (p == node->pt) return {INF, P()};
            return make_pair((p).manhattan(node->pt), node->pt);
        }

        Node *f = node->first, *s = node->second;
        T bfirst = f->distance(p), bsec = s->distance(p);
        if (bfirst > bsec)
            swap(bsec, bfirst), swap(f, s);

        // search closest side first, other side if needed
        auto best = search(f, p);
        if (bsec < best.first)
            best = min(best, search(s, p));
        return best;
    }

    // find nearest point to a point, and its squared distance
    // (requires an arbitrary operator< for Point)
    pair<T, P> nearest(const P& p)
    {
        return search(root, p);
    }
};
// https://github.com/kth-competitive-programming/kactl/blob/main/content/geometry/kdTree.h