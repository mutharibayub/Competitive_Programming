import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day15")

def solve(inp):
    ans = 0
    
    steps = inp.split(",")
    for step in steps:
        val = 0
        for c in step:
            val = (val + ord(c)) * 17 % 256
        ans += val
    
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))