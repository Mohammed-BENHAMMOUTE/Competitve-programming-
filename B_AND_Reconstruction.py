def solve_test_case():
    n = int(input())
    b = list(map(int, input().split()))
    
    a = [0] * n
    
    # Set a1
    a[0] = b[0]
    
    # Set a2 to an-1
    for i in range(1, n-1):
        a[i] = b[i-1] | b[i]
    
    # Set an
    a[n-1] = b[n-2]
    
    # Adjust values to satisfy conditions
    for i in range(n-1):
        if (a[i] & a[i+1]) != b[i]:
            # If conditions are not met, try to increase a[i] and a[i+1]
            mask = (1 << 30) - 1  # All 1's in binary
            while mask > 0:
                if (a[i] | mask) & (a[i+1] | mask) == b[i]:
                    a[i] |= mask
                    a[i+1] |= mask
                    break
                mask >>= 1
            if (a[i] & a[i+1]) != b[i]:
                return [-1]  # No solution exists
    
    return a

# Read the number of test cases
t = int(input())

# Solve each test case
for _ in range(t):
    result = solve_test_case()
    print(*result)