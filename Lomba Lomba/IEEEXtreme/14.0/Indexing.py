def punc(ch):
    return ch == ',' or ch == '.' or ch == '?' or ch == '!'
def normalize(text):
    text = text.lower()
    ret = ""
    for ch in text:
        if (punc(ch)):
            continue
        ret += ch
    return ret

score = {}
tot = 0

line = input().split(';')

stterm = {}
for kata in line:
    lkata = kata.lower()
    stterm[lkata] = True

sword = input().split(';')

idterm = {}
for kata in sword:
    lkata = kata.lower()
    idterm[lkata] = True

def boleh(c):
    return ord('a') <= ord(c) <= ord('z') or c == "'"

def proc(text, fac):
    text = text.lower()
    cur = ""
    all_cur = []
    ret = 0
    # Handle tags such as <index> </index> -> not counted
    for ch in text:
        if (boleh(ch)):
            cur += ch
        else:
            if (cur in idterm):
                all_cur.append(cur)
            if (len(cur) >= 4) and (cur not in stterm):
                print(cur)
                ret += 1
            cur = ""
    print()
    for kata in all_cur:
        if (kata not in score):
            score[kata] = 0
        score[kata] += fac
    return ret

html = ''
from sys import stdin
for line in stdin:
    html += line

html = normalize(html)
s = html.find('<title>') + 7
e = html.find('</title>')
# print(str(s) + " " + str(e))

tot += proc(html[s:e], 5)    

s = html.find('<abstract>') + 10
e = html.find('</abstract>')
# print(str(s) + " " + str(e))

tot += proc(html[s:e], 3)

s = html.find('<body>') + 6
e = html.find('</body>')
# print(str(s) + " " + str(e))

tot += proc(html[s:e], 1)

arr = []
for elem in score:
    arr.append((score[elem], elem))

print(tot)

from functools import cmp_to_key
def compare(a, b):
    if (a[0] > b[0]):
        return -1
    elif (a[0] < b[0]):
        return 1
    if (a[1] < b[1]):
        return -1
    return 1

custom_sort = cmp_to_key(compare)
arr = sorted(arr, key = custom_sort)
print(arr)
