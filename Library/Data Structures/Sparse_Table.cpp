// Taken from : https://github.com/mochow13/competitive-programming-library/blob/master/Data%20Structures/RMQ%20Sparse%20Table.cpp
// https://cp-algorithms.com/data_structures/sparse-table.html
template<int MAXN, int MAXLOG, typename T>
struct sparse_table {
	vector<vector<T>> dp;
	vector<int> prec_lg2;

	sparse_table() {
		dp.assign(MAXN, vector<int>(MAXLOG, 0));
		prec_lg2.assign(MAXN, 0);
	}

	T combine(const T& a, const T& b) {
		return min(a, b);
	}

	void init(vector<T> &a) {
		n = a.size();
		for (int i = 2; i < 2 * n; i++) {
			prec_lg2[i] = prec_lg2[i >> 1] + 1;
		}
		for (int i = 0; i < n; i++) {
			dp[i][0] = a[i];
		}
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; i < n; i++) {
				dp[i][j] = combine(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	T query(int l, int r) {
		int k = prec_lg2[r - l + 1];
		return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
	}
};
