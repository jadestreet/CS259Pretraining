

int isValidSudoku(char board[9][9]) {
    static short line[2][9];
    static short block[3][3];
    short mask[] = {1,2,4,8,16,32,64,128,256};
    
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j){
            printf("%d--%d\n", i, j);
            if(board[i][j] == '.')
                continue;
            
            if(line[0][i]&mask[board[i][j]-49])
                return 0;
            else 
                line[0][i] |= mask[board[i][j]-49];
                
            if(line[1][j]&mask[board[i][j]-49])
                return 0;
            else 
                line[1][j] |= mask[board[i][j]-49];
                
            if(block[i/3][j/3]&mask[board[i][j]-49])
                return 0;
            else 
                block[i/3][j/3] |= mask[board[i][j]-49];
        }
        
    return 1;
    
}

int main(int argc, char const *argv[])
{
    char board[9][9] = {"..4...63.", ".........", "5......9.", "...56....", "4.3.....1", "...7.....", "...5.....", ".........", "........."};
    printf("%d", isValidSudoku(board));
    return 0;
}