#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
    int count =0,n;
    printf("Enter n:\n");
    scanf("%d",&n);

    int *a = new int [n];

    for(int i = 0; i < n; i++){
        scanf("%d",a+i);
    }

    for(int i = 0; i < n; i++){
        if(i%2 && *(a+i) < 0){
//            printf("a[%d] = %d ",i,*(a+i));
            count++;
        }
    }
    printf("/n%d/n",count);
    system("pause");
}

