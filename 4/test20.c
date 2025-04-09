void solve(int (*sudoku)[9], int count);
 
int main(void){
    int sudoku[9][9], i, j;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            scanf("%d", &sudoku[i][j]);
        }
    }
 
    solve(sudoku, 0);
}
 
void solve(int (*sudoku)[9], int count){
    int index1, index2, i, failure, j, center1, center2, k1, k2, num1, num2;
    if(count == 81){
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
        exit(0);   
    }
    else{
        index1 = count/9;
        index2 = count%9;
 
        if(sudoku[index1][index2] != 0){ 
            solve(sudoku, count+1);
        }
        else{                              
            for(i=1; i<=9; i++){
                sudoku[index1][index2] = i;
                failure = 0;
                for(j=0; j<9; j++){
                    if(j!=index2 && sudoku[index1][j] == i)
                        failure = 1;
                    if(j!=index1 && sudoku[j][index2] == i)
                        failure = 1;
                }
               
                center1=0;  
                center2=0;  
                for(k1=1; k1<=7; k1= k1 + 3){
                    for(k2=1; k2<=7; k2 = k2 + 3){
                        if(abs(k1 - index1)<=1 && abs(k2 - index2)<=1){
                            center1 = k1;
                            center2 = k2;
                        }
                    }
                }
               
                for(num1=center1-1; num1<=center1+1; num1++){
                    for(num2=center2-1; num2<=center2+1; num2++){
                        if(num1==index1 && num2==index2)
                            continue;
                        else{
                            if(sudoku[num1][num2] == i)
                                failure = 1;
                        }
                    }
                }
            
                
                if(!failure){
                    solve(sudoku, count+1);
                }
                sudoku[index1][index2] = 0;
            }
        }
    }
}