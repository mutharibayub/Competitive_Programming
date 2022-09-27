with open('input.txt','r') as f:
    inputText = f.read()

rules = []
msgs = []
data = inputText.split('\n')
shift = False
for ele in data:
    if not shift:
        if ele.strip() == "":
            shift = True
        else:
            rules.append(ele)
    else:
        msgs.append(ele)

