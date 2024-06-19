def countDistinctPositions(x, y, z, k):
    max_positions = 0
    limit = int(k**(1/3)) + 2  # A slight increase in limit to ensure we cover all edge cases
    for a in range(1, limit):
        if k % a == 0:
            k_div_a = k // a
            for b in range(1, int(k_div_a**(1/2)) + 2):
                if k_div_a % b == 0:
                    c = k_div_a // b
                    if a <= x and b <= y and c <= z:
                        max_positions = max(max_positions, (x - a + 1) * (y - b + 1) * (z - c + 1))
                    if a <= x and c <= y and b <= z:
                        max_positions = max(max_positions, (x - a + 1) * (y - c + 1) * (z - b + 1))
                    if b <= x and a <= y and c <= z:
                        max_positions = max(max_positions, (x - b + 1) * (y - a + 1) * (z - c + 1))
                    if b <= x and c <= y and a <= z:
                        max_positions = max(max_positions, (x - b + 1) * (y - c + 1) * (z - a + 1))
                    if c <= x and a <= y and b <= z:
                        max_positions = max(max_positions, (x - c + 1) * (y - a + 1) * (z - b + 1))
                    if c <= x and b <= y and a <= z:
                        max_positions = max(max_positions, (x - c + 1) * (y - b + 1) * (z - a + 1))
    return max_positions

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        x = int(data[index])
        y = int(data[index + 1])
        z = int(data[index + 2])
        k = int(data[index + 3])
        index += 4
        results.append(countDistinctPositions(x, y, z, k))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
