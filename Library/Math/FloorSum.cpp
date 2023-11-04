// sum_{0 <= i < n} floor((a * i + b) / m)
long long floorSum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }
    long long y_max = (a * n + b) / m;
    long long x_max = (y_max * m - b);
    if (y_max == 0) {
        return ans;
    }
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floorSum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}