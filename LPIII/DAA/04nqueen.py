def safe(board,row,col):
    #check horizontal
    for i in range(col):
        if board[row][i]:
            return False
    #check diagonal
    r=row-1
    c=col-1
    while(r>=0 and c>=0):
        if board[r][c]==1:
            return False
        r-=1
        c-=1
    
    r=row+1
    c=col-1
    while(r<len(board) and c>=0):
        if board[r][c]==1:
            return False
        r+=1
        c-=1
    return True

def fun(board,col,n):
    if col==n:
        return True
    for i in range(n):
        if safe(board,i,col):
            board[i][col]=1
            if fun(board,col+1,n):
                return True
            board[i][col]=0
    return False


n=8
board = [[0 for _ in range(n)] for _ in range(n)]
print(board)
fun(board,0,n)
for row in board:
    for col in row:
        if col==0:
            print("-",end=" ")
        else:
            print("Q",end=" ")
    print("\n")