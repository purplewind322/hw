#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int deleteRow(int **matrix,int row_num, int n){
    printf("%d\n",row_num);
    int a;
    for(int i = row_num; i < n-1; i++){

        matrix[i] = matrix[i+1];

    }

    return n-1;
}

int main(){
    int a,current_row_sum = 0,max_row_sum = 0,max_row_sum_num = 0,n,m;
    printf("Enter m and n:\n");
    scanf("%d%d",&n,&m);

    int **matrix = new int* [n];
    printf("Enter matrix: \n");
    for (int i = 0; i < n; i++){
        matrix[i] = new int [m];

        for(int j = 0; j < m; j++){
            scanf("%d",&matrix[i][j]);
            if(i == 0){
                max_row_sum += matrix[i][j];


            }

            current_row_sum += matrix[i][j];

        }
        if(current_row_sum > max_row_sum){
            max_row_sum_num = i; max_row_sum = current_row_sum;
        }
        current_row_sum = 0;
}

    n = deleteRow(matrix,max_row_sum_num,n);
    delete [] matrix[n+1];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
    system("pause");

}

