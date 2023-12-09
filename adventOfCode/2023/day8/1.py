import os

os.chdir("./adventOfCode/2023/day8")

def solve(inp):
    ans = 0

    ins, als = inp.split("\n\n")
    al = {}
    for ll in als.split("\n"):
        s, r = [ele.strip().replace("(", "").replace(")", "") for ele in ll.split("=")]
        al[s] = [ele.strip() for ele in r.split(",")]

    idx = 0
    cur = "AAA"
    cnt = 0
    while True:
        if ins[idx] == "R":
            cur = al[cur][1]
        else:
            cur = al[cur][0]
        idx = (idx + 1)%len(ins)
        cnt += 1
        if cur == "ZZZ":
            break
        
    ans = cnt
    return ans

with open("sample1.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer1.txt", "r").read().strip()))
    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))