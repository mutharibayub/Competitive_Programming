import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day11")

IS_SAMPLE = True

def solve(inp):
    ans = 0
    
    grid = inp.split("\n")
    row_count = [0 for _ in range(len(grid))]
    col_count = [0 for _ in range(len(grid[0]))]
    
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '#':
                row_count[i] += 1
                col_count[j] += 1

    for i in range(len(row_count)):
        row_count[i] = 0 if row_count[i] > 0 else 1

    for i in range(1, len(row_count)):
        row_count[i] += row_count[i-1]

    for i in range(len(col_count)):
        col_count[i] = 0 if col_count[i] > 0 else 1

    for i in range(1, len(col_count)):
        col_count[i] += col_count[i-1]

    galaxies = []
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '#':
                galaxies.append((i, j))
    
    for i in range(len(galaxies)):
        for j in range(i+1, len(galaxies)):
            r1, c1 = galaxies[i]
            r2, c2 = galaxies[j]
            if r1 > r2:
                r1, r2 = r2, r1
            if c1 > c2:
                c1, c2 = c2, c1
            cost = 0
            cost += r2 - r1
            cost += c2 - c1
            cost += (row_count[r2] - row_count[r1]) * ((100 if IS_SAMPLE else 1000000) - 1)
            cost += (col_count[c2] - col_count[c1]) * ((100 if IS_SAMPLE else 1000000) - 1)   
            ans += cost 
    
    return ans

with open("sample2.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))    
    
IS_SAMPLE = False
    
with open("input.txt", "r") as f:
    print(solve(f.read()))