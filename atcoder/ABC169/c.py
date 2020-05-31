import math
from decimal import *

sa, sb = input().split()
a = Decimal(sa)
b = Decimal(sb)
lb = Decimal(b * Decimal(100))

ans = Decimal(Decimal(a * lb) // Decimal(100))
print(int(ans))
