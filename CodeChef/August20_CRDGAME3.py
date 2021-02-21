def game(pc, pr):
    if len(str(pc))==len(str(pr))==1:
        return 1,len(str(pc))
    c9 = pc//9
    cr = pc % 9
    r9 = pr//9
    rr = pr % 9
    if r9 + (1 if rr else 0) <= c9 + (1 if cr else 0):
        return 1, r9 + (1 if rr else 0)
    return 0, c9 + (1 if cr else 0)


if __name__=='__main__':
    T = int(input())
    for i in range(T):
        pc, pr = map(int, input().split())
        win,dig=game(pc,pr)
        print(f"{win} {dig}")