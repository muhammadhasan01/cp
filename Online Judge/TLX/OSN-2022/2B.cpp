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

const long long INF = 2e18;

int main() {
    IO::init();
    int n;
    IO::read_int(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        IO::read_int(a[i]);
    }
    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
        IO::read_int(w[i]);
    }
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        IO::read_int(v[i]);
    }
    vector<long long> dp(n, INF);
    vector<vector<int>> pos(n + 1);
    int last = 1;
    for (int i = 0; i < n; i++) {
        pos[a[i]].emplace_back(i);
        last = max(last, a[i]);
    }
    for (int i : pos[last]) {
        dp[i] = v[i];
    }
    for (int x = last - 1; x >= 1; x--) {
        int len = pos[x].size();
        if (len == 0) {
            continue;
        }
        int lstLen = pos[last].size();
        // Left to Right (i > j)
        {
            // dp[i] = (dp[j] - j) * w[i] + w[i] * i + v[i];
            long long mn = INF;
            for (int i = 0, j = 0; i < len; i++) {
                int cur = pos[x][i];
                while (j < lstLen && pos[last][j] <= cur) {
                    int p = pos[last][j];
                    mn = min(mn, dp[p] - p);
                    j++;
                }
                if (mn == INF) {
                    continue;
                }
                if (mn + cur >= INF / w[cur]) {
                    continue;
                }
                dp[cur] = min(dp[cur], (mn + cur) * w[cur] + v[cur]); 
            }
        }
        // Right to Left (i < j)
        {
            // dp[i] = (dp[j] + j) * w[i] - w[i] * i + v[i];
            long long mn = INF;
            for (int i = len - 1, j = lstLen - 1; i >= 0; i--) {
                int cur = pos[x][i];
                while (j >= 0 && pos[last][j] >= cur) {
                    int p = pos[last][j];
                    mn = min(mn, dp[p] + p);
                    j--;
                }
                if (mn == INF) {
                    continue;
                }
                if (mn - cur >= INF / w[cur]) {
                    continue;
                }
                dp[cur] = min(dp[cur], (mn - cur) * w[cur] + v[cur]);
            }
        }
        last = x;
    }
    long long ans = INF;
    for (int i : pos[last]) {
        ans = min(ans, dp[i]);
    }
    IO::write_int(ans, '\n');
    
    return 0;
}