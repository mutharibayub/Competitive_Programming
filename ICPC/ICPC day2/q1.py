
testCases = input()
outStr = ""
inputs = []
for _ in range(int(testCases)):
    t = input()
    inputs.append(t)
for i in range(int(testCases)):
    stk = []
    line = inputs[i]
    curLen = 0
    countSubstr = {}
    maxLen = -1
    for i in range(len(line)):
        if line[i] == "(":
            stk.append("(")
        elif len(stk)==0 and line[i]==")":
            if curLen!=0:
                if curLen not in countSubstr:
                    countSubstr[curLen] = 1
                else:
                    print(countSubstr)
                    countSubstr[curLen] += 1
                if maxLen<curLen:
                    maxLen = curLen
                curLen = 0
        else:
            stk.pop()
            curLen += 2
        if len(line)==i+1 and curLen != 0 and len(stk)==0:
            countSubstr[curLen] += 1
            if maxLen<curLen:
                maxLen = curLen
            curLen = 0
    if maxLen == -1:
        print("0 1")            
    else:
        print(f"{maxLen} {countSubstr[maxLen]}")