def s(a):
    o = []
    while len(set(a)) > 1 and len(o) < 40:
        m, M = min(a), max(a)
        x = (m + M) // 2
        o.append(x)
        a = [abs(v - x) for v in a]
    if len(set(a)) == 1 and a[0] != 0:
        o.append(a[0])
        a = [0] * len(a)
    return o if all(v == 0 for v in a) else None

for _ in range(int(input())):
    input()
    a = list(map(int, input().split()))
    r = s(a)
    if r is None:
        print(-1)
    else:
        print(len(r))
        print(*r) if r else print()