def solve(s):
    MOD = 10**9 + 7
    n = len(s)
    prefix_sum = 0
    sum_count = {0: 1}  # Initialize with 0 having count 1
    answer = 0

    for char in s:
        if char == '1':
            prefix_sum += 1
        else:
            prefix_sum -= 1
        
        # If we've seen this sum before, it means we have a balanced substring
        if prefix_sum in sum_count:
            answer += sum_count[prefix_sum]
        
        # Increment the count for this sum
        sum_count[prefix_sum] = sum_count.get(prefix_sum, 0) + 1

    return answer % MOD

# Read input and process test cases
t = int(input())
for _ in range(t):
    s = input().strip()
    print(solve(s))