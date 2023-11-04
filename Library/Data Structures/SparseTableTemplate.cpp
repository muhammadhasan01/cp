template<class T, class Fun = function<T(const T&, const T&)>>
struct SparseTable {
    vector<vector<T>> sp;
    Fun f;
 
    SparseTable(vector<T> &a, const Fun &g) : f(g) {
        int n = a.size();
        int lg = __lg(n) + 1;
        sp.resize(lg, vector<T>(n));
        for (int i = 0; i < n; i++) {
            sp[0][i] = a[i];
        }
        for (int j = 0; j < lg - 1; j++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << (j + 1)) > n) {
                    break;
                }
                sp[j + 1][i] = f(sp[j][i], sp[j][i + (1 << j)]);
            }
        }
    }
 
    T get(int l, int r) {
        int k = __lg(r - l + 1);
        return f(sp[k][l], sp[k][r - (1 << k) + 1]);
    }
};