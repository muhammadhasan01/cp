#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N = 2e5 + 5;
const int BLOCK_SIZE = 550;

int n, q;
int a[N];
int mp[N];
int numDistinct;

void del(int idx) {
    if (--mp[a[idx]] == 0) {
        numDistinct--;
    }
}

void add(int idx) {
    if (++mp[a[idx]] == 1) {
        numDistinct++;
    }
}

int get_answer() {
    return numDistinct;
}

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l / BLOCK_SIZE, r) < make_pair(other.l / BLOCK_SIZE, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    int cur_l = 0;
    int cur_r = -1;
    for (Query q : queries) {
        while (cur_l < q.l) del(cur_l++);
        while (cur_l > q.l) add(--cur_l);
        while (cur_r < q.r) add(++cur_r);
        while (cur_r > q.r) del(cur_r--);
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nums[i] = a[i];
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin() + 1;
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries[i] = {l, r, i};
    }
    vector<int> answer = mo_s_algorithm(queries);
    for (int ans : answer) {
        cout << ans << '\n';
    }
    
    return 0;
}