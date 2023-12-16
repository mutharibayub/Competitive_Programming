import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day16")

dir_mapping = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def pretty_print_grid(grid):
    grid = ["".join(ele) for ele in grid]
    for row in grid:
        print(row)

def solve(inp):
    ans = 0
    
    grid = inp.split("\n")
    done = set([(0, -1, 1)])
    q = [(0, -1, 1)]
    q_idx = 0
    while q_idx < len(q):
        r, c, dir = q[q_idx]
        q_idx += 1
        nr, nc = dir_mapping[dir]
        nr, nc = nr+r, nc+c
        if not (nr >= 0 and nr < len(grid) and nc >= 0 and nc < len(grid[0])):
            continue
        
        to_add = []
        
        if grid[nr][nc] == '.' or (dir in [1, 3] and grid[nr][nc] == '-') or (dir in [0, 2] and grid[nr][nc] == '|'):
            to_add = [(nr, nc, dir)]
        elif dir == 0:
            if grid[nr][nc] == '/':
                to_add = [(nr, nc, 1)]
            elif grid[nr][nc] == '\\':
                to_add = [(nr, nc, 3)]
            elif grid[nr][nc] == '-':
                to_add = [(nr, nc, 1), (nr, nc, 3)]
        elif dir == 2:
            if grid[nr][nc] == '/':
                to_add = [(nr, nc, 3)]
            elif grid[nr][nc] == '\\':
                to_add = [(nr, nc, 1)]
            elif grid[nr][nc] == '-':
                to_add = [(nr, nc, 1), (nr, nc, 3)]
        elif dir == 1:
            if grid[nr][nc] == '/':
                to_add = [(nr, nc, 0)]
            elif grid[nr][nc] == '\\':
                to_add = [(nr, nc, 2)]
            elif grid[nr][nc] == '|':
                to_add = [(nr, nc, 0), (nr, nc, 2)]
        elif dir == 3:
            if grid[nr][nc] == '/':
                to_add = [(nr, nc, 2)]
            elif grid[nr][nc] == '\\':
                to_add = [(nr, nc, 0)]
            elif grid[nr][nc] == '|':
                to_add = [(nr, nc, 0), (nr, nc, 2)]
             
        for nn in to_add:
            if nn not in done:
                done.add(nn)
                q.append(nn)  
    
    for i in range(len(grid)):
        for j in range(len(grid)):
            found = False
            for k in range(4):
                found = found or (i, j, k) in done
            ans += 1 if found else 0
                
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))