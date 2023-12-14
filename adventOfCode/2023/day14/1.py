import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day14")

def solve(inp):
    ans = 0
    
    grid = inp.split("\n")
    for i in range(len(grid[0])):
        cnt = 0
        for j in range(len(grid)):
            if grid[j][i] == '.':
                cnt += 1
            elif grid[j][i] == 'O':
                new_loc = j - cnt
                ans += len(grid) - new_loc
            elif grid[j][i] == '#':
                cnt = 0
                
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))