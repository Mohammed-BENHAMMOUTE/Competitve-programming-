import math

def solve():
    n = int(input())
    pt = []
    for _ in range(n):
        x, y = map(int, input().split())
        pt.append((x, y))
    
    xs, ys, xt, yt = map(int, input().split())
    
    mmDist = float('inf')
    for x, y in pt:
        temp = math.sqrt((x - xt)**2 + (y - yt)**2)
        mmDist = min(mmDist, temp)
    
    fn = math.sqrt((xs - xt)**2 + (ys - yt)**2)
    print(fn, mmDist)
    
    ans = "YES" if fn < mmDist else "NO"
    print(ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()