def min_colors(n):
    colors = [0] * (n + 1)
    for i in range(1, n + 1):
        if i % 4 == 1:
            colors[i] = 1
        elif i % 4 == 2:
            colors[i] = 2
        elif i % 4 == 3:
            colors[i] = 3
        else:  # i % 4 == 0
            colors[i] = 2
    
    max_color = max(colors[1:])
    return max_color, colors[1:]

t = int(input())
for _ in range(t):
    n = int(input())
    k, coloring = min_colors(n)
    print(k)
    print(*coloring)