def can_transform(n, m, a, b):
    for j in range(m):
        sum_a_col = sum(a[i][j] for i in range(n)) % 3
        sum_b_col = sum(b[i][j] for i in range(n)) % 3
        if sum_a_col != sum_b_col:
            return "NO"
    return "YES"

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])
    index += 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        
        a = []
        for _ in range(n):
            a.append([int(x) for x in data[index]])
            index += 1
        
        b = []
        for _ in range(n):
            b.append([int(x) for x in data[index]])
            index += 1
        
        results.append(can_transform(n, m, a, b))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
