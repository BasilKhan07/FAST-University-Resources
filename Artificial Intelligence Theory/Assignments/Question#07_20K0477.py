# To check if a given queen place is valid
def is_valid(board, row, col, n):
    # Checking for same row
    for i in range(col):
        if board[row][i] == 1:
            return False
    # Check for upper diagnol
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    # Check for lower diagnol
    for i, j in zip(range(row, n), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    # If place is valid
    return True

# To solve the N-Queens problem 
def solve_n_queens(n):
    # Initialize the board with zeros
    board = [[0 for _ in range(n)] for _ in range(n)]
    def solve_helper(board, col):
        # IF all queens have been placed
        if col == n:
            return True
        # Try placing queen in each row
        for row in range(n):
            # Check if the place is valid
            if is_valid(board, row, col, n):
                # Place the queen
                board[row][col] = 1
                # Recursive call to place the next queen
                if solve_helper(board, col + 1):
                    return True
                # Back track and remove queen
                board[row][col] = 0
        # If no valid placement is found, return False for backtrack
        return False
    solve_helper(board, 0)
    # Print the final board
    for row in board:
        print(row)

solve_n_queens(4) 
numOfQueens = int(input("Enter number of Queens: "))
solve_n_queens(numOfQueens)