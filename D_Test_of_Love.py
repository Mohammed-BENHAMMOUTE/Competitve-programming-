def can_ernkor_cross(n, m, k, river):
    # Initialize the starting position
    position = 0
    swam = 0

    # Queue for BFS: (current_position, swam_distance)
    queue = [(position, swam)]
    visited = set(queue)

    while queue:
        current_position, current_swam = queue.pop(0)

        # Check if we can jump directly to the right bank
        if current_position + m >= n + 1:
            return "YES"
        
        # Try to jump to positions within the jump limit
        for jump in range(1, m + 1):
            next_position = current_position + jump

            if next_position == n + 1:
                return "YES"
            
            if next_position <= n:
                if river[next_position - 1] == 'L' and (next_position, current_swam) not in visited:
                    queue.append((next_position, current_swam))
                    visited.add((next_position, current_swam))
                elif river[next_position - 1] == 'W' and (next_position, current_swam + jump) not in visited:
                    if current_swam + jump <= k:
                        queue.append((next_position, current_swam + jump))
                        visited.add((next_position, current_swam + jump))
    
    return "NO"

# Read input
import sys
input = sys.stdin.read
data = input().split()

t = int(data[0])
index = 1

results = []

for _ in range(t):
    n = int(data[index])
    m = int(data[index + 1])
    k = int(data[index + 2])
    river = data[index + 3]
    index += 4
    
    result = can_ernkor_cross(n, m, k, river)
    results.append(result)

# Print results
for result in results:
    print(result)
