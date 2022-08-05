import random

def test_gen(stalls, cows):
    stall_locs = set()
    while len(stall_locs)<stalls:
        stall_locs.add(str(random.randint(0,1000000000)))
    return f"{stalls} {cows}\n{' '.join(list(stall_locs))}"
    
test_cases = 1

test = str(test_cases)+"\n"
for i in range(test_cases):
    stalls = random.randint(2,100)
    cows = random.randint(2,stalls)
    test += test_gen(stalls,cows) + "\n"

with open("text.txt",'w') as f:
    f.write(test)
