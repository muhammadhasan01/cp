#include <bits/stdc++.h>

using namespace std;

struct mint {
    const int MOD = 1e9 + 7;
    int x;

    mint(int _x) : x((_x % MOD + MOD) % MOD) {}
    mint(long long _x) : x((_x % MOD + MOD) % MOD) {}

    mint() : x(0) {}

    mint &operator=(const mint &rhs) {
        x = rhs.x;
        return *this;
    }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = mint(1);
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator+=(const mint &rhs) {
        x += rhs.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }

    mint &operator-=(const mint &rhs) {
        x -= rhs.x;
        if (x < 0)
            x += MOD;
        return *this;
    }

    mint &operator*=(const mint &rhs) {
        unsigned long long z = x;
        z *= rhs.x;
        x = (unsigned int)(z % MOD);
        return *this;
    }

    mint &operator/=(const mint &rhs) {
        return *this = *this * rhs.inv();
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }

    friend mint operator/(const mint &lhs, const mint &rhs) {
        return mint(lhs) /= rhs;
    }

    friend ostream& operator<<(ostream &os, const mint &m) {
        return os << m.x;
    }
};

class Token {
public:
    enum class Type {
        Unknown,
        Number,
        Operator,
        LeftParen,
        RightParen,
    };

    Token(Type t, const std::string& s, int prec = -1, bool ra = false)
        : type { t }, str ( s ), precedence { prec }, rightAssociative { ra }
    {}

    const Type type;
    const std::string str;
    const int precedence;
    const bool rightAssociative;
};

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << token.str;
    return os;
}

std::deque<Token> exprToTokens(const std::string& expr) {
    std::deque<Token> tokens;

    for(const auto* p = expr.c_str(); *p; ++p) {
        if(isblank(*p)) {
            // do nothing
        } else if(isdigit(*p)) {
            const auto* b = p;
            while(isdigit(*p)) {
                ++p;
            }
            const auto s = std::string(b, p);
            tokens.push_back(Token { Token::Type::Number, s });
            --p;
        } else {
            Token::Type t = Token::Type::Unknown;
            int pr = -1;            // precedence
            bool ra = false;        // rightAssociative
            switch(*p) {
            default:                                    break;
            case '(':   t = Token::Type::LeftParen;     break;
            case ')':   t = Token::Type::RightParen;    break;
            case '^':   t = Token::Type::Operator;      pr = 4; ra = true;  break;
            case '*':   t = Token::Type::Operator;      pr = 3; break;
            case '/':   t = Token::Type::Operator;      pr = 3; break;
            case '+':   t = Token::Type::Operator;      pr = 2; break;
            case '-':   t = Token::Type::Operator;      pr = 2; break;
            }
            const auto s = std::string(1, *p);
            tokens.push_back(Token { t, s, pr, ra });
        }
    }
    return tokens;
}


std::deque<Token> shuntingYard(const std::deque<Token>& tokens) {
    std::deque<Token> queue;
    std::vector<Token> stack;

    // While there are tokens to be read:
    for(auto token : tokens) {
        // Read a token
        switch(token.type) {
        case Token::Type::Number:
            // If the token is a number, then add it to the output queue
            queue.push_back(token);
            break;

        case Token::Type::Operator:
            {
                // If the token is operator, o1, then:
                const auto o1 = token;

                // while there is an operator token,
                while(!stack.empty()) {
                    // o2, at the top of stack, and
                    const auto o2 = stack.back();

                    // either o1 is left-associative and its precedence is
                    // *less than or equal* to that of o2,
                    // or o1 if right associative, and has precedence
                    // *less than* that of o2,
                    if(
                        (! o1.rightAssociative && o1.precedence <= o2.precedence)
                    ||  (  o1.rightAssociative && o1.precedence <  o2.precedence)
                    ) {
                        // then pop o2 off the stack,
                        stack.pop_back();
                        // onto the output queue;
                        queue.push_back(o2);

                        continue;
                    }

                    // @@ otherwise, exit.
                    break;
                }

                // push o1 onto the stack.
                stack.push_back(o1);
            }
            break;

        case Token::Type::LeftParen:
            // If token is left parenthesis, then push it onto the stack
            stack.push_back(token);
            break;

        case Token::Type::RightParen:
            // If token is right parenthesis:
            {
                bool match = false;

                // Until the token at the top of the stack
                // is a left parenthesis,
                while(! stack.empty() && stack.back().type != Token::Type::LeftParen) {
                    // pop operators off the stack
                    // onto the output queue.
                    queue.push_back(stack.back());
                    stack.pop_back();
                    match = true;
                }

                // Pop the left parenthesis from the stack,
                // but not onto the output queue.
                if (stack.empty()) {
                    return {};
                }
                stack.pop_back();


                if(!match && stack.empty()) {
                    // If the stack runs out without finding a left parenthesis,
                    // then there are mismatched parentheses.
                    // printf("RightParen error (%s)\n", token.str.c_str());
                    return {};
                }
            }
            break;

        default:
            // printf("error (%s)\n", token.str.c_str());
            return {};
        }

        // debugReport(token, queue, stack);
    }

    // When there are no more tokens to read:
    //   While there are still operator tokens in the stack:
    while(! stack.empty()) {
        // If the operator token on the top of the stack is a parenthesis,
        // then there are mismatched parentheses.
        if(stack.back().type == Token::Type::LeftParen) {
            // printf("Mismatched parentheses error\n");
            return {};
        }

        // Pop the operator onto the output queue.
        queue.push_back(std::move(stack.back()));
        stack.pop_back();
    }

    // debugReport(Token { Token::Type::Unknown, "End" }, queue, stack);

    //Exit.
    return queue;
}


int main() {
    int n;
    cin >> n;
    vector<string> expressions(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string res = "";
        for (char cc : s) {
            if (cc == ')') {
                res += '+';
                res += '0';
            }
            res += cc;
        }
        expressions[i] = res;
    }
    for(const auto& expr : expressions) {
        const auto tokens = exprToTokens(expr);
        auto queue = shuntingYard(tokens);
        int len = expr.size();
        bool ok = true;
        for (int i = 1; i < len; i++) {
            if (expr[i - 1] == ')' && isdigit(expr[i])) {
                ok = false;
            }
            if (isdigit(expr[i - 1]) && expr[i] == '(') {
                ok = false;
            }
            if (expr[i - 1] == ')' && expr[i] == '(') {
                ok = false;
            }
        }
        if (!ok) {
            cout << "invalid" << '\n';
            continue;
        }
        std::vector<mint> stack;
        try {
            while(! queue.empty()) {
                const auto token = queue.front();
                queue.pop_front();
                switch(token.type) {
                case Token::Type::Number:
                    stack.push_back(std::stoi(token.str));
                    break;
                case Token::Type::Operator:
                    {
                        if (stack.empty()) {
                            break;
                        }
                        const auto rhs = stack.back();
                        stack.pop_back();
                        if (stack.empty()) {
                            break;
                        }
                        const auto lhs = stack.back();
                        stack.pop_back();

                        switch(token.str[0]) {
                        default:
                            stack.clear();
                            break;
                        case '^':
                            // stack.push_back(static_cast<int>(pow(lhs, rhs)));
                            break;
                        case '*':
                            stack.push_back(lhs * rhs);
                            break;
                        case '/':
                            stack.push_back(lhs / rhs);
                            break;
                        case '+':
                            stack.push_back(lhs + rhs);
                            break;
                        case '-':
                            stack.push_back(lhs - rhs);
                            break;
                        }
                    }
                    break;

                default:
                    stack.clear();
                    break;
                }
                // debugReport(token, queue, stack, op);
            }   
        } catch (...) {
            stack.clear();
        }
        if (stack.empty()) {
            cout << "invalid" << '\n';
            continue;
        }
        cout << stack.back() << '\n';
    }
}