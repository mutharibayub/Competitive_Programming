import random
t_cnt = 20
n_range = (1, 20)

input_txt = ""
input_txt += str(t_cnt)+"\n"
for t in range(t_cnt):
    n = random.randint(*n_range)
    m = random.randint(1, n)
    k = random.randint(1, n)
    perm = [i+1 for i in range(n)]
    idx = [i for i in range(n)]
    random.shuffle(idx)
    random.shuffle(perm)
    aft = []
    for i in range(m):
        aft.append(idx[i])
    aft = sorted(aft)
    aft = [perm[aft[i]] for i in range(len(aft))]
    tools = [random.randint(1, n) for _ in range(k)]
    input_txt += ' '.join([str(ele) for ele in [n, m, k]]) + '\n'
    input_txt += ' '.join([str(ele) for ele in perm]) + '\n'
    input_txt += ' '.join([str(ele) for ele in aft]) + '\n'
    input_txt += ' '.join([str(ele) for ele in tools]) + '\n'

with open("testCases.txt", "w") as f:
    f.write(input_txt)
    
