def dfs(node, adj, visited):
    visited[node] = True
    has_edge = False
    
    for neighbor in adj[node]:
        has_edge = True
        if not visited[neighbor]:
            dfs(neighbor, adj, visited)
    
    return has_edge

def solve():
    n, m = map(int, input().split())
    
    adj = [[] for _ in range(n + 1)]
    
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    
    visited = [False] * (n + 1)
    component_count = 0
    
    for i in range(1, n + 1):
        if not visited[i] and adj[i]:  # Only consider nodes with at least one edge
            if dfs(i, adj, visited):
                component_count += 1
    
    print(component_count)

solve()
