#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int main(){
    IO::init();
    int T;
    IO::read_int(T);
    while(T--){
        int n;
        IO::read_int(n);
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            IO::read_int(a[i]);
        }
        // 1) build frequencies
        vector<int> freq(n+1, 0);
        for(int v : a) freq[v]++;

        // 2) threshold B = sqrt(n)+1
        int B = int(sqrt(n)) + 1;

        // 3) split into heavy vs light
        vector<int> heavy, light;
        for(int v = 1; v <= n; v++){
            if(freq[v] > 0){
                if(freq[v] > B) heavy.push_back(v);
                else           light.push_back(v);
            }
        }

        // 4) answer array for sums up to 2n
        vector<ll> ans(2*n+1, 0);

        // 5) heavy–light & heavy–heavy
        int H = heavy.size();
        // heavy–any
        for(int i = 0; i < H; i++){
            int x = heavy[i];
            ll fx = freq[x];
            // pair with light values
            for(int y: light){
                ans[x + y] += min<ll>(fx, freq[y]);
            }
            // pair with other heavies, unordered
            for(int j = i; j < H; j++){
                int y = heavy[j];
                if(x == y){
                    // self‐pair
                    ans[2*x] += fx/2;
                } else {
                    ans[x + y] += min<ll>(fx, freq[y]);
                }
            }
        }

        // 6) light–light (brute over distinct light values)
        int L = light.size();
        for(int i = 0; i < L; i++){
            int u = light[i];
            ll fu = freq[u];
            // self‐pair
            ans[2*u] += fu/2;
            // distinct pairs u<v
            for(int j = i+1; j < L; j++){
                int v = light[j];
                ans[u + v] += min<ll>(fu, freq[v]);
            }
        }

        // 7) output answers for k = 1 .. 2n
        //    (ans[1] will be 0 automatically)
        for(int k = 1; k <= 2*n; k++){
            IO::write_int(ans[k], ' ');
        }
        IO::write_char('\n');
    }

    return 0;
}
