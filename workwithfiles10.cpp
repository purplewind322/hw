#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>


void createRandomNumbers(int *a){
    for(int i = 0; i < 40; i++){
        a[i] = rand() % 41;
    }
}

int main() {
    FILE *file1 = fopen("file1.txt", "w");
    FILE *file2 = fopen("file2.txt","w");
    int a[40];
    int b[40];
    int x;
    createRandomNumbers(a);
    if(!file1){
        printf("Error!");
        return -1;
    }
    if(!file2){
        printf("Error!");
        return -1;
    }
    for(int i = 0; i < 40; i++){
        fprintf(file1, "%d\n", a[i]);
    }
    fclose(file1);
    FILE *file3 = fopen("file1.txt", "r");
    int n = 0;
    while(n < 40){
        n++;
        fscanf(file3,"%d",&x);
        printf("%d\n",x);
        if(!(x%5)){
            fprintf(file2,"%d\n",x);
        }
    }
    fclose(file1);
    fclose(file2);
}