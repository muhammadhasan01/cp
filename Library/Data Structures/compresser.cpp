template<typename T>
struct compresser {
    vector<T> nums;
    
    compresser(vector<T>& v) {
        nums.assign(v.begin(), v.end());
        finish();
    }
 
    void add(T x) {
        nums.emplace_back(x);
    }
 
    void finish() {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    }
 
    int get_id(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }
 
    int get_len() {
        return nums.size();
    }
};