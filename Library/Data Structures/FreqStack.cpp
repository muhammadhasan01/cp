template<typename T>
vector<pair<T, int>> getFreq(vector<T>& v) {
    vector<pair<T, int>> freq;
    for (T x : v) {
        if (freq.empty() || freq.back().first != x) {
            freq.emplace_back(x, 1);
            continue;
        }
        auto [_, cnt] = freq.back();
        freq.pop_back();
        freq.emplace_back(x, cnt + 1);
    }
    return freq;
}