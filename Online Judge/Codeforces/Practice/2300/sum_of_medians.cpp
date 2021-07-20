#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int BLOCK = 250;
const int NUM_BLOCK = N / BLOCK + 3;
const int K = 5;

int n;
int bit[N];
pair<char, int> op[N];
long long values[N];
long long dp[NUM_BLOCK][K];
bitset<N> is_added;

void add(int x, int val) {
    is_added[x] = (val > 0);
    for ( ; x < N; x += x & -x) {
        bit[x] += val;
    }
}

int get(int x) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x) {
        ret += bit[x];
    }
    return ret;
}

void rebuild_dp(int block_pos) {
    for (int i = 0; i < K; i++) {
        dp[block_pos][i] = 0LL;
    }
    int start = (block_pos - 1) * BLOCK + 1;
    int kth = -1;
    for (int i = start; i <= start + BLOCK - 1; i++) {
        if (is_added[i] == 0) {
            continue;
        }
        if (kth == -1) {
            kth = get(i) % 5;
        } else {
            kth = (kth + 1) % 5;
        }
        dp[block_pos][kth] += values[i];
    }
}

void config_dp(int block_pos, int move) {
    vector<long long> temp(K);
    for (int block = block_pos + 1; block < NUM_BLOCK; block++) {
        for (int i = 0; i < K; i++) {
            temp[i] = dp[block][i];
        }
        for (int i = 0; i < K; i++) {
            int ni = i + move;
            if (ni < 0) {
                ni = K - 1;
            } else if (ni == K) {
                ni = 0;
            }
            dp[block][i] = temp[ni];
        }
    }
}

void add_num(int x) {
    add(x, 1);
    int block_pos = (x + BLOCK - 1) / BLOCK;
    rebuild_dp(block_pos);
    config_dp(block_pos, -1);
}

void del_num(int x) {
    add(x, -1);
    int block_pos = (x + BLOCK - 1) / BLOCK;
    rebuild_dp(block_pos);
    config_dp(block_pos, 1);
}

long long get_sum() {
    long long ret = 0;
    for (int block = 1; block < NUM_BLOCK; block++) {
        ret += dp[block][3];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        if (str[0] == 's') {
            op[i].second = -1;
        } else {
            cin >> op[i].second;
        }
        op[i].first = str[0];
        nums.emplace_back(op[i].second);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (int i = 1; i <= n; i++) {
        int id = lower_bound(nums.begin(), nums.end(), op[i].second) - nums.begin() + 1;
        values[id] = op[i].second;
        op[i].second = id;
    }
    for (int i = 1; i <= n; i++) {
        auto [cc, num] = op[i];
        if (cc == 'a') {
            add_num(num);
        } else if (cc == 'd') {
            del_num(num);
        } else if (cc == 's') {
            cout << get_sum() << '\n';
        }
    }

    return 0;
}