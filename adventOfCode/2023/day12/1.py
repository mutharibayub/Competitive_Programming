import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day12")

def cnt(seq, arr, cur, last_dot, idx):
    
    if len(seq) == idx:
        if len(arr) == len(cur) and not (len(cur) > 0 and cur[-1] != arr[-1]):
            return 1
        return 0
    
    ans = 0
    allowed = ['.', '#'] if seq[idx] == '?' else [seq[idx]]
    for to_put in allowed:
        if to_put == '.':
            ans += cnt(seq, arr, cur, True, idx + 1)
        else:
            can_do = True
            if last_dot:
                cur.append(1)
                if len(cur) > len(arr) or (len(cur) > 1 and cur[len(cur) - 2] != arr[len(cur)-2]):
                    can_do = False
            else:
                cur[-1] += 1
                if arr[len(cur)-1] < cur[len(cur)-1]:
                    can_do = False
            if can_do:
                ans += cnt(seq, arr, cur, False, idx + 1)
            if last_dot:
                cur.pop()
            else:
                cur[-1] -= 1
    return ans


def solve(inp):
    ans = 0
    
    rows = inp.split("\n")
    for row in rows:
        seq, arr = row.split(" ")
        arr = [int(ele.strip()) for ele in arr.split(",") if ele.strip() != ""]
        ans += cnt(seq, arr, [], True, 0)
    
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))