import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day13")

def solve(inp):
    ans = 0
    
    blocks = inp.split("\n\n")
    for block in blocks:
        block = block.split("\n")
        arr = []
        for i in range(len(block[0])):
            num = 0
            for j in range(len(block)):
                if block[j][i] == '.':
                    continue
                num += (1<<j)
            arr.append(num)
        found = None
        for i in range(len(arr) - 1):
            ok = True
            for j in range(min(i, len(arr) - i - 2) + 1):
                if arr[i - j] != arr[i + j + 1]:
                    ok = False
                    break
            if ok:
                found = i
                break
        if found is not None:
            ans += found + 1
            continue
        arr = []
        for i in range(len(block)):
            num = 0
            for j in range(len(block[i])):
                if block[i][j] == '.':
                    continue
                num += (1<<j)
            arr.append(num)
        found = None
        for i in range(len(arr) - 1):
            ok = True
            for j in range(min(i, len(arr) - i - 2) + 1):
                if arr[i - j] != arr[i + j + 1]:
                    ok = False
                    break
            if ok:
                found = i
                break
        if found is not None:
            ans += found * 100 + 100
    
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))