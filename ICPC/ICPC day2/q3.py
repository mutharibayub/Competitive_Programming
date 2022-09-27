
testCases = int(input())
outStr = ""
for i in range(testCases):
    val = input()
    (rows, cols) = tuple([int(ele) for ele in val.split(' ')])
    totalSeats = rows*cols
    outStr += f"{totalSeats} {int((totalSeats*(totalSeats+1))/2)}\n"

print(outStr, end="")