
def testCase(str1, str2):
    dict = {}
    possible = True
    for char in str1:
        if char not in dict:
            dict[char] = 1
        else:
            dict[char] += 1
    for char in str2:
        if char not in dict or dict[char]==0:
            possible = False
            break
        else:
            dict[char] -= 1
    return "Possible\n" if possible else "Not Possible\n" 

testCases = int(input())
inputs = []
outStr =""
for _ in range(testCases):
    t1 = input()
    t2 = input()
    inputs.append((t1,t2))
for i in range(testCases):
    outStr += testCase(inputs[i][0],inputs[i][1])

print(outStr, end="")