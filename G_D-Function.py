def digit_sum(n):
    return sum(int(digit) for digit in str(n))

def satisfies_condition(n, k):
    dn = digit_sum(n)
    return digit_sum(k * n) == k * dn

MOD = 10**9 + 7

def solve_case(l, r, k):
    count = 0
    lower_bound = 10**l
    upper_bound = 10**r
    if k == 1:
        # All numbers in the range [10^l, 10^r) satisfy the condition when k = 1
        count = upper_bound - lower_bound
    else:
        # Only check the first few hundred numbers due to periodicity of digit sums
        for n in range(lower_bound, min(lower_bound + 1000, upper_bound)):
            if satisfies_condition(n, k):
                count += 1
        # Scale up by estimating periodicity
        count *= (upper_bound - lower_bound) // 1000
        for n in range(lower_bound + ((upper_bound - lower_bound) // 1000) * 1000, upper_bound):
            if satisfies_condition(n, k):
                count += 1
        count %= MOD
    return count

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    t = int(data[0])
    index = 1
    results = []
    for _ in range(t):
        l = int(data[index])
        r = int(data[index+1])
        k = int(data[index+2])
        results.append(solve_case(l, r, k))
        index += 3
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
