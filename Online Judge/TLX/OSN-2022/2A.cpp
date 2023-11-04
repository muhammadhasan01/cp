#include <bits/stdc++.h>

using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }

    inline bool input_finished() {
        while (isspace(next_char(false)) && input_len > 0)
            next_char();

        return input_len < BUFFER_SIZE && input_pos >= input_len;
    }

    inline void read_char(char &c) {
        while (isspace(next_char(false)))
            next_char();

        c = next_char();
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    inline void read_double(double &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (next_char(false) == '.') {
            next_char();

            for (double multiplier = 0.1; isdigit(next_char(false)); multiplier *= 0.1)
                number += multiplier * (next_char() - '0');
        }

        if (negative)
            number = -number;
    }

    inline void read_str(string &str) {
        while (isspace(next_char(false)))
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
    }

    inline void read_line(string &str) {
        while (next_char(false) == '\n')
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (next_char(false) != '\n');
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }

        if (number != 0 || length == 0)
            write_char(char(number + '0'));

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    inline void write_str(const string &str, char after = '\0') {
        for (char c : str)
            write_char(c);

        if (after)
            write_char(after);
    }

    inline void write_double(double number, char after = '\0', int places = 6) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        assert(number <= 9e18);

        // Round up the number according to places.
        number += 0.5 * pow(0.1, places);
        int64_t floored = int64_t(number);

        if (floored <= numeric_limits<int>::max())
            write_int(int(floored));
        else
            write_int(floored);

        number -= double(floored);

        if (number < 0 || number >= 1)
            number = 0;

        if (places > 0) {
            write_char('.');

            while (places >= 2) {
                number *= 100;
                int two = int(number);
                number -= two;
                uint8_t lookup_value = lookup[two];
                write_char(char((lookup_value >> 4) + '0'));
                write_char(char((lookup_value & 15) + '0'));
                places -= 2;
            }

            if (places == 1) {
                number *= 10;
                int one = int(number);
                write_char(char(one + '0'));
            }
        }

        if (after)
            write_char(after);
    }

    void init() {
        // Ensures that _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}

const long long INF = 1e18;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<deque<pair<long long, int>>> values;
    
    DSU(int n) : n(n), par(n), sz(n), values(n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    int getSize(int u) {
        int pu = fpar(u);
        return sz[pu];
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        for (auto [val, pos] : values[pv]) {
            values[pu].emplace_back(val, pos);
        }
        values[pv].clear();
        return true;
    }
};

int main() {
    IO::init();
    int n, m, q;
    IO::read_int(n, m, q);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        long long h;
        IO::read_int(h);
        dsu.values[i].emplace_back(h, i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        IO::read_int(u, v);
        --u, --v;
        dsu.merge(u, v);
    }
    int numComponent = 0;
    vector<int> comps;
    for (int u = 0; u < n; u++) {
        if (dsu.fpar(u) == u) {
            numComponent++;
            comps.emplace_back(u);
        }
    }
    vector<pair<long long, int>> smallest;
    for (int i = 0; i < numComponent; i++) {
        int u = comps[i];
        deque<pair<long long, int>>& values = dsu.values[u];
        int len = values.size();
        if (len <= 1) {
            continue;
        }
        sort(values.begin(), values.end());
        for (int j = 1; j < len; j++) {
            smallest.emplace_back(values[j].first, i);
        }
    }
    sort(smallest.begin(), smallest.end());
    int need = numComponent - 2;
    vector<int> cnt(numComponent, 1);
    for (auto [_, pos] : smallest) {
        if (need <= 0) {
            break;
        }
        cnt[pos]++;
        need--;
    }
    set<pair<int, int>> compSt;
    for (int i = 0; i < numComponent; i++) {
        compSt.emplace(cnt[i], comps[i]);
    }
    long long cost = 0;
    vector<pair<int, int>> edges;
    while ((int) compSt.size() >= 2) {
        auto U = compSt.begin();
        auto V = prev(compSt.end());
        auto [cu, u] = *U;
        auto [cv, v] = *V;
        auto [valU, posU] = dsu.values[u].front();
        auto [valV, posV] = dsu.values[v].front();
        cost += valU + valV;
        edges.emplace_back(posU, posV);
        dsu.values[u].pop_front();
        dsu.values[v].pop_front();
        compSt.erase(V);
        compSt.erase(U);
        if (cu > 1) {
            compSt.emplace(cu - 1, u);
        }
        if (cv > 1) {
            compSt.emplace(cv - 1, v);
        }
    }
    for (auto [u, v] : edges) {
        dsu.merge(u, v);
    }
    if (dsu.getSize(0) < n) {
        IO::write_int(-1, '\n');
        return 0;
    }
    IO::write_int(cost, '\n');
    if (q == 1) {
        IO::write_int(edges.size(), '\n');
        for (auto [u, v] : edges) {
            IO::write_int(u + 1, ' ');
            IO::write_int(v + 1, '\n');
        }
    }

    return 0;
}