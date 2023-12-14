import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day14")

def pretty_print_grid(grid):
    for row in grid:
        print(row)

def sim_movement(grid, dir):
    
    new_grid = [["." for _ in range(len(grid[0]))] for _ in range(len(grid))]

    if dir == (-1, 0):
        for i in range(len(grid[0])):
            cnt = 0
            for j in range(len(grid)):
                if grid[j][i] == '.':
                    cnt += 1
                elif grid[j][i] == 'O':
                    new_loc = j - cnt
                    new_grid[new_loc][i] = 'O'
                elif grid[j][i] == '#':
                    cnt = 0
                    new_grid[j][i] = '#'
    elif dir == (1, 0):
        for i in range(len(grid[0])):
            cnt = 0
            for j in range(len(grid)-1, -1, -1):
                if grid[j][i] == '.':
                    cnt += 1
                elif grid[j][i] == 'O':
                    new_loc = j + cnt
                    new_grid[new_loc][i] = 'O'
                elif grid[j][i] == '#':
                    cnt = 0
                    new_grid[j][i] = '#'
    elif dir == (0, -1):
        for i in range(len(grid)):
            cnt = 0
            for j in range(len(grid[0])):
                if grid[i][j] == '.':
                    cnt += 1
                elif grid[i][j] == 'O':
                    new_loc = j - cnt
                    new_grid[i][new_loc] = 'O'
                elif grid[i][j] == '#':
                    cnt = 0
                    new_grid[i][j] = '#'
    elif dir == (0, 1):
        for i in range(len(grid)):
            cnt = 0
            for j in range(len(grid[0])-1, -1, -1):
                if grid[i][j] == '.':
                    cnt += 1
                elif grid[i][j] == 'O':
                    new_loc = j + cnt
                    new_grid[i][new_loc] = 'O'
                elif grid[i][j] == '#':
                    cnt = 0
                    new_grid[i][j] = '#'
                
    return ["".join(row) for row in new_grid]
                    
def do_cycle(grid):
    for dir in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
        grid = sim_movement(grid, dir)
    return grid   
                    
def calc_load(grid):
    ans = 0
    for i in range(len(grid[0])):
        cnt = 0
        for j in range(len(grid)):
            if grid[j][i] == 'O':
                ans += len(grid) - j
    return ans

def solve(inp):
    ans = 0
    
    todo = 1000000000
    
    grid = inp.split("\n")
    states = {}
    
    states[tuple(grid)] = 0
    i = 0
    while i < todo:
    
        grid = do_cycle(grid)
    
        i += 1

        tmp = tuple(grid)
        if tmp in states:
            cycle_size = i - states[tmp]
            tt = (todo - i) // cycle_size * cycle_size
            i += tt
            states = {}

        states[tmp] = i
    ans = calc_load(grid)
                
    return ans

with open("sample2.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))