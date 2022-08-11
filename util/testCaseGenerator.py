import random
import os

def test_gen(lower_lim, upper_lim):
    num1 = random.randint(lower_lim, upper_lim)
    num2 = -1
    while num2 == -1 or (num2-num1)%2==1:
        num2 = random.randint(lower_lim, num1-1) 
    return f"{num1} {num2}"
    
test_cases = 10

# test = str(test_cases)+"\n"
test = ""
for i in range(test_cases):
    lower_lim = 0
    upper_lim = int(1e10)
    test += test_gen(lower_lim, upper_lim) + "\n"

input_file = os.path.join(os.path.curdir, "outputCompare","input.txt")
with open(input_file,'w') as f:
    f.write(test)
