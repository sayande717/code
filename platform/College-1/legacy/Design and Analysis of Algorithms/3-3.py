def isSafe(board, row, col, n):
    for iter in range(col):
        if board[row][iter] == 1:
            return False

    for iter, jter in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[iter][jter] == 1:
            return False

    for iter, jter in zip(range(row, n, 1), range(col, -1, -1)):
        if board[iter][jter] == 1:
            return False

    return True

def solveNQueensUtil(board, col, n):
    # BASE Case
    if col >= n:
        return True

    
    for iter in range(n):
        
        if isSafe(board, iter, col, n):
            board[iter][col] = 1
            
            if solveNQueensUtil(board, col + 1, n):
                return True

            board[iter][col] = 0  # backtrack

    return False

def solveNQueens(n):
    board = [[0] * n for _ in range(n)]

    if not solveNQueensUtil(board, 0, n):
        print("Solution does not exist")
        return False

    for row in board:
        print(" ".join(str(x) for x in row))
    return True

def main():
    n = int(input("Enter the value of N: "))
    solveNQueens(n)
    
main()
