tst = int(input())
for _ in range(tst):
    n = int(input())
    s = input()
    f = [0 for i in range(3)]
    cur_bal = n
    cnt_bal = [0 for i in range(2 * n + 1)]
    cnt_bal[cur_bal] += 1
    f[cur_bal % 3] += 1
    ans = 0
    for i in range(n):
        new_bal = cur_bal
        if s[i] == '-':
            new_bal -= 1
            f[new_bal % 3] += cnt_bal[new_bal]
            ans += f[new_bal % 3]
            cnt_bal[new_bal] += 1
            f[new_bal % 3] += 1
        else:
            f[new_bal % 3] -= cnt_bal[new_bal]
            new_bal += 1
            ans += f[new_bal % 3]
            cnt_bal[new_bal] += 1
            f[new_bal % 3] += 1
        cur_bal = new_bal
        print("x"*10)
        print(s[:i+1])
        print(cnt_bal)
        print(f)
        print(cur_bal, ans)
    print(ans)