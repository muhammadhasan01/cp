#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define inchar          getchar
#define outchar(x)      putchar(x)

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = inchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = inchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = inchar());
    for (; c > 47 && c < 58; c = inchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}
template<typename T> void outpos(T n) {
    if (n < 0) {
        outchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) outchar(snum[i--]);
    outchar('\n');
}