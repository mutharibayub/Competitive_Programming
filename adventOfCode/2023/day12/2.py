import os
from copy import copy

os.chdir("./adventOfCode/2023/day12")

def get_cnt(seq, arr, cur, last_dot, idx, cnt, base_cnt):
    
    if len(seq) == idx:
        if len(cur) <= len(arr):
            k = (tuple(cur), last_dot)
            if k not in cnt:
                cnt[k] = 0
            cnt[k] += base_cnt
        return
    
    ans = 0
    allowed = ['.', '#'] if seq[idx] == '?' else [seq[idx]]
    for to_put in allowed:
        if to_put == '.':
            get_cnt(seq, arr, cur, True, idx + 1, cnt, base_cnt)
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
                get_cnt(seq, arr, cur, False, idx + 1, cnt, base_cnt)
            if last_dot:
                cur.pop()
            else:
                cur[-1] -= 1


def solve(inp):
    ans = 0
    
    rows = inp.split("\n")
    for row in rows:
        seq, arr = row.split(" ")
        seq += "?"
        arr = [int(ele.strip()) for ele in arr.split(",") if ele.strip() != ""]
        arr = arr + arr + arr + arr + arr
        cnt = {((), True): 1}
        for _ in range(5):
            new_cnt = {}
            for (cur, last_dot), base_cnt in cnt.items():
                cur = list(cur)
                get_cnt(seq, arr, cur, last_dot, 0, new_cnt, base_cnt)
            cnt = copy(new_cnt)
        
        tans = 0
        if (tuple(arr), True) in cnt:
            tans = cnt[(tuple(arr), True)]
        ans += tans
    
    return ans

with open("sample2.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))