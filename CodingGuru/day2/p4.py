testCases = int(input())
for i in range(testCases):
    s = input().split(' ')
    f = int(s[0])
    a = int(s[1])
    c = int(s[2])
    print(f"Case #{i+1}:",int((f+a+c)/3))