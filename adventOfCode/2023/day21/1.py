import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day20")

def solve(inp, steps):
    ans = 0
    
    grid = inp.split("\n")
    start = None
    for i in range(len(grid)):
        for j in range(len(grid)):
            if grid[i][j] == 'S':
                start = (i, j)
                
    current = set([start])
    for _ in range(steps):
        next = set()
        for r, c in current:
            for cr, cc in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
                nr, nc = r + cr, c + cc
                if nr >= len(grid) or nr < 0 or nc >= len(grid[0]) or nc < 0 or grid[nr][nc] == '#':
                    continue
                next.add((nr, nc))                
        current = next
    
    ans = len(current)
    
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read(), 6)
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read(), 64))