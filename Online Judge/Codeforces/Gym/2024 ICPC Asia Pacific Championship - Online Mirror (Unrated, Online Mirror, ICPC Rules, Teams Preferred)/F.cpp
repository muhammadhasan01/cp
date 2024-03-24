#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int N = 1e6 + 5;

int a[N];
int sum[N];

deque<pair<int, int>> low, hig;

void add(int x, int v) {
    while (!low.empty() && low.front().first >= v) low.pop_front();
    low.emplace_front(v, x);
    while (!hig.empty() && hig.front().first <= v) hig.pop_front();
    hig.emplace_front(v, x);
};

void rem(int til) {
    while (!low.empty() && low.back().second == til) low.pop_back();
    while (!hig.empty() && hig.back().second == til) hig.pop_back();
};

pii get(int v) {
    int mini = v, maxi = v;
    if (!low.empty()) mini = min(low.back().first, v);
    if (!hig.empty()) maxi = max(hig.back().first, v);
    return {maxi, mini};
};

bool compare(const pii& x, const pii& y) {
    return 1LL* x.first * y.second < 1LL * x.second * y.first;
}

void solve() {
  int n;
  IO::read_int(n);
  for (int i = 0; i < n; i++) {
    IO::read_int(a[i]);
  }
  pii ans = {0, 1};
  bool first = true;
  int cnt = 0;
  for (int g = 2; g <= n; ++g) {
    if (n % g) continue;
    if (++cnt > 3) {
        break;
    }
    for (int i = 0; i < g; i++) {
        sum[i] = 0;
    }
    deque<pair<int, int>>().swap(low);
    deque<pair<int, int>>().swap(hig);
    for (int i = 0, j = 0; i < n; ++i, ++j) {
      if (j == g) j = 0;
      sum[j] += a[i];
    }
    for (int i = 0; i < g; ++i) {
      add(i, sum[i]);
    }
    pii cur = {hig.back().first, low.back().first};
    if (first || compare(cur, ans)) {
      ans = cur;
      first = false;
    }
    int num = g, now = 0;
    for (int i = 1; i < n; ++i, ++num) {
      int pre = now;
      ++now;
      if (now == g) now = 0;
      int diff = a[i] - a[0];
      sum[pre] += diff;
      sum[now] += -diff;
      add(num, sum[pre]);
      rem(num - (g-1));
      rem(num - g);
      cur = get(sum[now]);
      if (compare(cur, ans)) {
        ans = cur;
      }
    }
    if (ans.first == ans.second) {
      IO::write_int(1, ' ');
      IO::write_int(1, '\n');
      return;
    }
  }
  int d = __gcd(ans.first, ans.second);
  ans.first /= d;
  ans.second /= d;
  IO::write_int(ans.first, ' ');
  IO::write_int(ans.second, '\n');
}

int main() {
  IO::init();
  int tt;
  IO::read_int(tt);
  while (tt--) {
    solve();
  }
  return 0;
}
