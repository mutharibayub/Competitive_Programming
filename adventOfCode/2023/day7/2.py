import os

os.chdir("./adventOfCode/2023/day7")

mp = ["A", "K", "Q", "T", "9", "8", "7", "6", "5", "4", "3", "2", "J"]
mp = list(reversed(mp))
strength = {ele: idx for idx, ele in enumerate(mp)}

def getStrength(s):
    out = 0
    mul = 1
    for c in reversed(s):
        out += strength[c] * mul
        mul *= 13
    return out

def getType(s):
    counts = {}
    for c in s:
        if c not in counts:
            counts[c] = 1
            continue
        counts[c] += 1
    cc = [v for k, v in counts.items() if k != 'J']
    jCount = counts['J'] if 'J' in counts else 0
    cc.sort(reverse=True)
    if len(cc) == 0:
        cc.append(jCount)
    else:
        cc[0] += jCount
    return -len(cc), cc

def solve(inp):
    ans = 0
    vals = [ele.split(" ") for ele in inp.split("\n")]
    vals = sorted(vals, key = lambda x: (getType(x[0]), getStrength(x[0])))
    for idx, (_, score) in enumerate(vals):
        ans += (idx + 1) * int(score)
    return ans

with open("sample.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer.txt", "r").read().strip()))
    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))