import random

ss = set()

while(len(ss)!=1000):
    ss.add(str(random.randint(2,1000000000)))

sss = ",".join(ss)

with open('out.txt','w') as f:
    f.write('[')
    f.write(sss)
    f.write(']')

# print(ss)