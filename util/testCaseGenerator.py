import random
import os

def test_gen(lower_lim, upper_lim):
    return chr(random.randint(49,57)) + ''.join([chr(random.randint(48,57)) for _ in range(lower_lim-1, upper_lim)])
    
def main():
    test_cases = 100000

    test = str(test_cases)+"\n"
    # test = ""
    for i in range(test_cases):
        lower_lim = 0
        upper_lim = 5
        test += test_gen(lower_lim, upper_lim) + "\n"

    input_file = os.path.join(os.path.curdir, "outputCompare","input.txt")

    with open(input_file,'w') as f:
        f.write(test)

if __name__ == "__main__":
    main()
