def stabilize_matrix(matrix, n, m):
    while True:
        max_i, max_j = -1, -1
        max_value = -1
        found = False

        for i in range(n):
            for j in range(m):
                is_greater = True
                if i > 0 and matrix[i][j] <= matrix[i-1][j]:
                    is_greater = False
                if i < n-1 and matrix[i][j] <= matrix[i+1][j]:
                    is_greater = False
                if j > 0 and matrix[i][j] <= matrix[i][j-1]:
                    is_greater = False
                if j < m-1 and matrix[i][j] <= matrix[i][j+1]:
                    is_greater = False
                
                if is_greater:
                    if not found or matrix[i][j] > max_value or (matrix[i][j] == max_value and (i < max_i or (i == max_i and j < max_j))):
                        max_i, max_j = i, j
                        max_value = matrix[i][j]
                        found = True
        
        if not found:
            break
        
        matrix[max_i][max_j] -= 1

    return matrix

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])
    index += 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        
        matrix = []
        for i in range(n):
            row = list(map(int, data[index:index + m]))
            index += m
            matrix.append(row)
        
        stabilized_matrix = stabilize_matrix(matrix, n, m)
        results.append(stabilized_matrix)
    
    for result in results:
        for row in result:
            print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()
