testCases = int(input())

outputStr =""
for i in range(testCases):
    inputStr = input().strip('<').strip('>')
    vals = [int(ele) for ele in inputStr.split(',')]
    sum = 0
    while len(vals)!=1:
        sum += vals[0]+vals[-1]
        if vals[0]>vals[-1]:
            vals = vals[1:]
        else:
            vals.pop()
    outputStr += str(sum)+"\n"

print(outputStr, end="")