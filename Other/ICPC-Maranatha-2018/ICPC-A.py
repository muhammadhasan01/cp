def encode(a):
    if a == 'a':
        return "ei"
    elif a == 'b':
        return "bi"
    elif a == 'c':
        return "si"
    elif a == 'd':
        return "di"
    elif a == 'e':
        return "i"
    elif a == 'f':
        return "ef"
    elif a == 'g':
        return "dei"
    elif a == 'h':
        return "eitf"
    elif a == 'i':
        return "ai"
    elif a == 'j':
        return "djei"
    elif a == 'k':
        return "kei"
    elif a == 'l':
        return "el"
    elif a == 'm':
        return "em"
    elif a == 'n':
        return "en"
    elif a == 'o':
        return "ou"
    elif a == 'p':
        return "pi"
    elif a == 'q':
        return "kiu"
    elif a == 'r':
        return "ar"
    elif a == 's':
        return "es"
    elif a == 't':
        return "ti"
    elif a == 'u':
        return "ju"
    elif a == 'v':
        return "vi"
    elif a == 'w':
        return "dabelju"
    elif a == 'x':
        return "eks"
    elif a == 'y':
        return "wai"
    elif a == 'z':
        return "zi"
    else:
        return a

a = input()
na = ""
for i in a:
    na += encode(i)
print(na)
