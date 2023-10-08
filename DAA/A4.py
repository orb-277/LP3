global N
import copy
N = 4
sol = []

def printSolution(board):
    for i in range(N):
        for j in range(N):
            print(board[i][j],end=' ')
        print('\n')

def isSafe(board,row,col):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i,j in zip(range(row,-1,-1),range(col,-1,-1)):
        if board[i][j] == 1:
            return False
    for i,j in zip(range(row,N,1),range(col,-1,-1)):
        if board[i][j] == 1:
            return False
    return True

def helper(board,col):
    if col >= N:
        sol.append(copy.deepcopy(board))
        print()
        return 
    for i in range(N):
        if isSafe(board,i,col):
            board[i][col] = 1
            helper(board,col+1)
            board[i][col] = 0
    

def solve():
    board=[[0] * N for _ in range(N)]
    helper(board,0)
    print(sol)
    print(len(sol))

solve()
        


        