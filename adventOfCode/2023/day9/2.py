import os

os.chdir("./adventOfCode/2023/day9")

def getNext(sequence):
    
    diff = []
    same = True
    for i in range(len(sequence)-1):
        diff.append(sequence[i+1] - sequence[i])
        if i > 0:
            same = (same and diff[-1] == diff[-2])
    if same:
        return diff[-1] + sequence[-1]
    
    return getNext(diff) + sequence[-1]

def solve(inp):
    ans = 0
    
    sequences = [[int(ele.strip()) for ele in ele1.strip().split(" ") if ele.strip() != ""] for ele1 in inp.split("\n")]
    for sequence in sequences:
        sequence = list(reversed(sequence))
        ans += getNext(sequence)
    
    return ans

with open("sample2.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))