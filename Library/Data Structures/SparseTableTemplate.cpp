template<class T, class Fun = function<T(const T&, const T&)>>
struct SparseTable {
    vector<vector<T>> sp;
    Fun f;
 
    SparseTable(vector<T> &a, const Fun &g) : f(g) {
        int n = a.size();
        int lg = __lg(n) + 1;
        sp.resize(n, vector<T>(lg));
        for (int i = 0; i < n; i++) {
            sp[i][0] = a[i];
        }
        for (int j = 0; j < lg - 1; j++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << (j + 1)) > n) {
                    break;
                }
                sp[i][j + 1] = f(sp[i][j], sp[i + (1 << j)][j]);
            }
        }
    }
 
    T get(int l, int r) {
        int k = __lg(r - l + 1);
        return f(sp[l][k], sp[r - (1 << k) + 1][k]);
    }
};