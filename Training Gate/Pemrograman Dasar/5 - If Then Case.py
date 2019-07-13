a = int(input())
if 1 <= a <= 9:
    print('satuan')
elif 10 <= a <= 99:
    print('puluhan')
elif 100 <= a <= 999:
    print('ratusan')
elif 1000 <= a <= 9999:
    print('ribuan')
else:
    print('puluhribuan')

