import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day19")

def evaluate(x, m, a, s, cond):
    mp = {"x": x, "m": m, "a": a, "s": s}
    if cond == "":
        return True
    if "<" in cond:
        var, chk = cond.split("<")
        return mp[var] < int(chk)
    if ">" in cond:
        var, chk = cond.split(">")
        return mp[var] > int(chk)
    assert(False)        
    

def solve(inp):
    ans = 0
    
    als, ss = inp.split("\n\n")
    als = als.split("\n")
    al = {}
    for ele in als:
        ii, oth = ele.split("{")
        oth = oth[: -1].split(",")
        al[ii] = []
        for rule in oth:
            if ":" not in rule:
                al[ii].append(("", rule))
                continue
            cond, next = rule.split(":")
            al[ii].append((cond, next))

    ss = ss.split("\n")
    for start in ss:
        x, m, a, s = [int(ele.split("=")[1]) for ele in start[1: -1].split(",")]
        cur = "in"
        while cur not in ["A", "R"]:
            for cond, next in al[cur]:
                if evaluate(x, m, a, s, cond):
                    cur = next
                    break 
        if cur == "A":
            ans += x + m + a + s        
    
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))