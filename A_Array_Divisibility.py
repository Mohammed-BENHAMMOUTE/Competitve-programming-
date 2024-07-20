def beautiful_arrays(t, test_cases):
    results = []
    for n in test_cases:
        # Generate the array [n+1, n+2, ..., 2n]
        array = [i + n for i in range(1, n+1)]
        results.append(array)
    return results

# Input handling
t = int(input())
test_cases = [int(input()) for _ in range(t)]

# Generate and print results
results = beautiful_arrays(t, test_cases)
for result in results:
    print(' '.join(map(str, result)))
