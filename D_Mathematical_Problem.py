def evaluate_expression(expr):
    parts = expr.split('+')
    total = 0
    for part in parts:
        factors = list(map(int, part.split('*')))
        product = 1
        for factor in factors:
            product *= factor
        total += product
    return total

def solve(test_cases):
    results = []
    
    for s in test_cases:
        n = len(s)
        
        # If length is 2, directly append the integer value
        if n == 2:
            results.append(int(s))
            continue
        
        min_result = float('inf')
        
        # Generate all combinations of `+` and `*` for `n-2` operations
        # Start from 1 to n-1 for operators placement
        for i in range(1, n):
            for j in range(i+1, n):
                expr = s[:i] + '*' + s[i:j] + '+' + s[j:]
                result = evaluate_expression(expr)
                min_result = min(min_result, result)
        
        results.append(min_result)
    
    return results

# Example usage:
t = int(input().strip())  # Number of test cases
test_cases = []
for _ in range(t):
    n = int(input().strip())  # Length of the string
    s = input().strip()       # The string itself
    test_cases.append(s)

# Solve the problem for each test case
output = solve(test_cases)

# Print the results
for result in output:
    print(result)
