# Used to generate te testcases

import random

qtt = int(input())
print(qtt)
for x in range(qtt):
    if x != qtt-1:
        print(round(random.uniform(0,51),2), round(random.uniform(0,51),2), random.randint(-3,11))
    else:
        print(round(random.uniform(0,51),2), round(random.uniform(0,51),2), random.randint(-3,11), end='')
        