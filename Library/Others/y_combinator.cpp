// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
    public:
        template<class T> explicit y_combinator_result(T && fun): fun_(forward<T> (fun)) {}
    template<class...Args> decltype(auto) operator()(Args &&...args) {
        return fun_(ref(*this), forward<Args>(args)...);
    }
};

template<class Fun> decltype(auto) y_combinator(Fun && fun) {
    return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun));
}

auto fact = y_combinator([&](auto self, int x) -> void {
    if (x == 0) {
        return 1;
    }
    return self(x - 1) * x;
});
cout << fact(5) << '\n';