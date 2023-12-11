import os

os.chdir("./adventOfCode/2023/day10")

def solve(inp):
    ans = 0
    
    grid = inp.split("\n")
    
    starting = None
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 'S':
                starting = i, j
                break
        if starting is not None:
            break
    assert(starting is not None)
    
    current = starting
    parent = None
    dist = 0
    while True:
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
            
    return dist // 2

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))