def mPegunungan(num):
    if num == 1:
        print("*")
    else:
        mPegunungan(num-1)
        print("*"*num)
        mPegunungan(num-1)
mPegunungan(int(input()))
