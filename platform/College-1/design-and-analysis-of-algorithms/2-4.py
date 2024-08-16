def matrixChainMul(p):
    n = len(p) - 1
    m = [[0] * (n + 1) for _ in range(n + 1)]
    s = [[0] * (n + 1) for _ in range(n + 1)]

    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

    return m[1][n]

def main():
    # Matrix A: 5x10
    # Matrix B: 10x3
    # Matrix C: 3x12
    # Matrix D: 12x5
    # Matrix E: 5x50
    # Matrix F: 50x6
    
    dimensionArray = [5, 10, 3, 12, 5, 50, 6]
    print(f"Dimensions array as per question: {dimensionArray}")
    
    minimumMultiplications = matrixChainMul(dimensionArray)
    print(f"Minimum scalar multiplications needed: {minimumMultiplications}")

main()