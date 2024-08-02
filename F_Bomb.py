from heapq import heapify, heappush, heappop

def max_score(n, k, a, b):
    # Create a max heap of (a[i], b[i]) pairs
    heap = [(-a[i], b[i]) for i in range(n)]
    heapify(heap)
    
    score = 0
    
    while k > 0 and heap:
        neg_a, b = heappop(heap)
        a = -neg_a
        
        # Add the current maximum to the score
        score += a
        k -= 1
        
        # Calculate the new a value
        new_a = a - b
        
        # If the new a is positive, push it back to the heap
        if new_a > 0:
            heappush(heap, (-new_a, b))
    
    return score

# Read number of test cases
t = int(input())

for _ in range(t):
    # Read n and k
    n, k = map(int, input().split())
    
    # Read array a
    a = list(map(int, input().split()))
    
    # Read array b
    b = list(map(int, input().split()))
    
    # Calculate and print the maximum score
    print(max_score(n, k, a, b))