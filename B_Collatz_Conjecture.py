def solve_collatz_conjecture(test_cases):
    results = []
    for x, y, k in test_cases:
        for _ in range(k):
            x += 1
            while x % y == 0:
                x //= y
        results.append(x)
    return results

# Read input
import sys
input = sys.stdin.read
data = input().split()

t = int(data[0])
index = 1
test_cases = []
for _ in range(t):
    x = int(data[index])
    y = int(data[index + 1])
    k = int(data[index + 2])
    test_cases.append((x, y, k))
    index += 3

# Solve the problem
results = solve_collatz_conjecture(test_cases)

# Print results
for result in results:
    print(result)
