import os
from queue import PriorityQueue, Queue

os.chdir("./adventOfCode/2023/day20")

def solve(inp, steps):    
    ans = 0
    
    final_par = steps%2
    
    grid = inp.split("\n")
    start = None
    for i in range(len(grid)):
        for j in range(len(grid)):
            if grid[i][j] == 'S':
                start = (i, j)
                
    dist = {start: 0}
    q = Queue()
    q.put(start) 
    ans += final_par^1
    
    while not q.empty():
        r, c = q.get()
        cur_dist = dist[(r, c)]
        for cr, cc in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
            nr, nc = r + cr, c + cc
            if grid[nr%(len(grid)+len(grid))%len(grid)][nc%(len(grid[0])+len(grid[0]))%len(grid[0])] == '#' \
                or (nr, nc) in dist or cur_dist == steps:
                continue
            next_dist = cur_dist + 1
            dist[(nr, nc)] = next_dist
            q.put((nr, nc))
            ans += int( next_dist%2 == final_par )
                
    return ans

with open("sample2.txt", "r") as f:
    ans = solve(f.read(), 5000)
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read(), 26501365))