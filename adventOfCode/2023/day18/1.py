import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day18")

dir_mapping = {'U': (-1, 0), 'R': (0, 1), 'D': (1, 0), 'L': (0, -1)}

def solve(inp):
    ans = None
    
    mnr, mnc, mxr, mxc = 0, 0, 0, 0
    
    cmds = inp.split("\n")
    vis = set()
    loc = 0, 0
    for cmd in cmds:
        dir, ln, _ = cmd.split(" ")
        for _ in range(int(ln)):
            n_loc = loc[0] + dir_mapping[dir][0], loc[1] + dir_mapping[dir][1]
            vis.add(n_loc)
            mnr = min(mnr, n_loc[0])
            mnc = min(mnc, n_loc[1])
            mxr = max(mxr, n_loc[0])
            mxc = max(mxc, n_loc[1])
            loc = n_loc
    
    count = (mxr - mnr + 1) * (mxc - mnc + 1)
    stk = []
    for i in range(mnr, mxr+1, 1):
        if (i, mnc) not in vis:
            stk.append((i, mnc))
        if (i, mxc) not in vis:
            stk.append((i, mxc))
    for i in range(mnc + 1, mxc, 1):
        if (mnr, i) not in vis:
            stk.append((mnr, i))
        if (mxr, i) not in vis:
            stk.append((mxr, i))
    outer = set(stk)
    while len(stk) > 0:
        t_loc = stk[-1]
        stk.pop()
        for c_dir in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
            n_loc = t_loc[0] + c_dir[0], t_loc[1] + c_dir[1]
            nr, nc = n_loc
            if n_loc in vis or nr < mnr or nr > mxr or nc < mnc or nc > mxc or n_loc in outer:
                continue
            outer.add(n_loc)
            stk.append(n_loc)
    ans = count - len(outer)
    
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))