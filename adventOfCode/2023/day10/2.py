import os

os.chdir("./adventOfCode/2023/day10")

def prettyPrintGrid(grid):
    for row in grid:
        if type(row) == str:
            print(row)
        elif type(row) == list:
            print(''.join(row))

def solve(inp):
    ans = 0
    
    grid = inp.split("\n")
    starting = None
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 'S':
                starting = i, j
    assert(starting is not None)
    
    current = starting
    parent = None
    dist = 0
    next = {}
    prev = {}
    while True:
        prev[current] = parent
        if dist > 0 and current == starting:
            break
        i, j = current
        if i - 1 >= 0 and (i-1, j) != parent and grid[i][j] in ['S', '|', 'J', 'L'] and grid[i-1][j] in ['S', '|', 'F', '7']:
            current = i-1, j
            dist += 1
        elif j - 1 >= 0 and (i, j-1) != parent and grid[i][j] in ['S', '-', '7', 'J'] and grid[i][j-1] in ['S', '-', 'F', 'L']:
            current = i, j-1
            dist += 1
        elif i + 1 < len(grid) and (i+1, j) != parent and grid[i][j] in ['S', '|', 'F', '7'] and grid[i+1][j] in ['S', '|', 'J', 'L']:
            current = i+1, j
            dist += 1
        elif j + 1 < len(grid[0]) and (i, j+1) != parent and grid[i][j] in ['S', '-', 'F', 'L'] and grid[i][j+1] in ['S', '-', '7', 'J']:
            current = i, j+1
            dist += 1
        parent = i, j
        next[parent] = current
       
    new_grid = [['_' for _ in range(len(grid[0]) * 2)] for _ in range(len(grid) * 2)]
    new_next = {}
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            new_grid[i*2][j*2] = grid[i][j]
            new_grid[i*2+1][j*2] = 'X'
            new_grid[i*2][j*2+1] = 'X'
            new_grid[i*2+1][j*2+1] = 'X'
            if (i, j) not in next:
                continue
            assert((i, j) in prev)
            diff = i - prev[(i, j)][0], j - prev[(i, j)][1]
            if diff[0] == -1:
                new_grid[i*2+1][j*2] = '|'            
                new_next[(i*2+1, j*2)] = (i*2, j*2)
                new_next[(i*2+2, j*2)] = (i*2+1, j*2)
            elif diff[1] == -1:
                new_grid[i*2][j*2+1] = '-'            
                new_next[(i*2, j*2+1)] = (i*2, j*2)
                new_next[(i*2, j*2+2)] = (i*2, j*2+1)
            diff = next[(i, j)][0] - i, next[(i, j)][1] - j
            if diff[0] == 1:
                new_grid[i*2+1][j*2] = '|'            
                new_next[(i*2, j*2)] = (i*2+1, j*2)
                new_next[(i*2+1, j*2)] = (i*2+2, j*2)
            elif diff[1] == 1:
                new_grid[i*2][j*2+1] = '-'            
                new_next[(i*2, j*2)] = (i*2, j*2+1)
                new_next[(i*2, j*2+1)] = (i*2, j*2+2)

    grid = new_grid
            
    outer = []
    for i in range(len(grid)):
        outer.append((i, 0))
        outer.append((i, len(grid[0])-1))
    for i in range(len(grid[0])):
        outer.append((0, i))
        outer.append((len(grid)-1, i))        
    outer = list(set([(r, c) for r, c in outer if (r, c) not in new_next]))
    
    outerIdx = 0
    vis = set(outer)
    while outerIdx < len(outer):
        curr, curc = outer[outerIdx]
        outerIdx += 1
        for chr, chc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nxtr = chr + curr
            nxtc = chc + curc
            if nxtr >= 0 and nxtr < len(grid) and nxtc >= 0 and nxtc < len(grid[0]) and (nxtr, nxtc) not in vis \
                and (nxtr, nxtc) not in new_next:
                    outer.append((nxtr, nxtc))
                    vis.add((nxtr, nxtc))

    totalDots = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            totalDots += 1 if (i, j) not in new_next and grid[i][j] != 'X' else 0

    outerDots = 0
    for r, c in outer:
        outerDots += 1 if grid[r][c] not in new_next and grid[r][c] != 'X' else 0
            
    return totalDots - outerDots

with open("sample2.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))