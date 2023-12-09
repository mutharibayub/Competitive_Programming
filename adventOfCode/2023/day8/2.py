import os

os.chdir("./adventOfCode/2023/day8")

def gcd(a, b):
    if a < b:
        a, b = b, a
    if not b:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b//gcd(a, b)

def get_lcms(li, idx, cur):
    out = []
    if idx == len(li):
        return [cur]
    for ele in li[idx]:
        nCur = lcm(cur, ele)
        out.extend(get_lcms(li, idx + 1, nCur))
    return out 

def solve(inp):
    ans = 0

    ins, als = inp.split("\n\n")
    al = {}
    starting = set()
    for ll in als.split("\n"):
        s, r = [ele.strip().replace("(", "").replace(")", "") for ele in ll.split("=")]
        al[s] = [ele.strip() for ele in r.split(",")]
        if s[2] == 'A':
            starting.add(s)

    vals = []
    for start in starting:
        cVals = []
        idx = 0
        cur = start
        cnt = 0
        done = set([(cur, idx)])
        while True:
            if ins[idx] == "R":
                cur = al[cur][1]
            else:
                cur = al[cur][0]
            idx = (idx + 1)%len(ins)
            cnt += 1
            if cur[2] == "Z":
                cVals.append(cnt)
            if (cur, idx) in done:
                break
            done.add((cur, idx))
        vals.append(cVals)
    tmp = get_lcms(vals, 0, 1)
    ans = sorted(tmp)[0]
    return ans

with open("sample2.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))
    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))