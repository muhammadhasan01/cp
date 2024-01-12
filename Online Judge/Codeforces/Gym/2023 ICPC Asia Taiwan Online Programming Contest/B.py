from decimal import Decimal, ROUND_DOWN

rt, rj, st, sj = map(Decimal, input().split())

st *= Decimal('100')
sj *= Decimal('100')

pt = st.to_integral_value(rounding=ROUND_DOWN)
pj = sj.to_integral_value(rounding=ROUND_DOWN)

ft = (rt - Decimal('1')) * pj
fj = (rj - Decimal('1')) * pt

if ft < fj:
    print("TAOYUAN")
elif ft > fj:
    print("JAKARTA")
else:
    print("SAME")