import os
from queue import PriorityQueue

os.chdir("./adventOfCode/2023/day15")

def solve(inp):
    ans = 0
    
    boxes_size = [0 for _ in range(256)]
    boxes = [{} for _ in range(256)]
    steps = inp.split(",")
    for step in steps:
        
        remove = '-' in step
        label = step.replace('-', '=').split("=")[0]
    
        hash = 0
        for c in label:
            hash = (hash + ord(c)) * 17 % 256
        
        if remove:
            boxes[hash].pop(label) if label in boxes[hash] else None
            continue
            
        focal_length = int(step.split("=")[1])
            
        if label in boxes[hash]:
            last_idx = boxes[hash][label][0]
            boxes[hash][label] = (last_idx, focal_length)
            continue            
        
        boxes[hash][label] = (boxes_size[hash], focal_length)
        boxes_size[hash] += 1
        
    for box_number, box in enumerate(boxes):
        nums = [v for k, v in box.items()]
        nums.sort()
        
        for idx, (_, focal_length) in enumerate(nums):
            ans += (box_number + 1) * (idx + 1) * focal_length
    
    return ans

with open("sample2.txt", "r") as f:
    ans = solve(f.read())
    print(ans)
    assert(ans == int(open("sampleAnswer2.txt", "r").read().strip()))    
    
with open("input.txt", "r") as f:
    print(solve(f.read()))