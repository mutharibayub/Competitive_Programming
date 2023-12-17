import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day17")

dir_mapping = [(-1, 0), (0, 1), (1, 0), (0, -1)]
nxt_drs = [[1, 3], [0, 2], [1, 3], [0, 2]]

def solve(inp):
    ans = None
    
    grid = inp.split("\n")
    fr = len(grid) - 1
    fc = len(grid[0]) - 1
    
    min_heat_loss = [[[[10000 for _ in range(len(grid[0]))] for _ in range(len(grid))] for _ in range(4)] for _ in range(4)]
    pq = [[] for _ in range(10*(len(grid) + len(grid[0])))]
    pq[0].append((1, 0, 0, 0))
    pq[0].append((2, 0, 0, 0))
    for mhl in range(10*(len(grid) + len(grid[0]))):
        if mhl:
            pq[mhl-1] = []
            
        for ldr, trv, rr, cc in pq[mhl]:
        
            if min_heat_loss[ldr][trv][rr][cc] != 10000:
                continue
        
            if rr == fr and cc == fc:
                ans = mhl
                break
        
            min_heat_loss[ldr][trv][rr][cc] = mhl
        
            next_dirs = nxt_drs[ldr] + [ldr]
            if trv == 3:
                next_dirs.pop()
                
            for dir in next_dirs:
                nr, nc = dir_mapping[dir]
                nr, nc = nr+rr, nc+cc
                if not (nr >= 0 and nr < len(grid) and nc >= 0 and nc < len(grid[0])):
                    continue
                nxt_cst = mhl + int(grid[nr][nc])
                nxt_tup = (dir, trv+1 if dir == ldr else 1, nr, nc)
                pq[nxt_cst].append(nxt_tup)

        if ans is not None:
            break
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))