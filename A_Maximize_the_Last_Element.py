def solve_test_case():
    n = int(input())
    a = list(map(int, input().split()))
    
    max_val = a[0]  
    for i in range(2, n, 2): 
        max_val = max(max_val, a[i])
    
    return max_val


t = int(input())


for _ in range(t):
    result = solve_test_case()
    print(result)