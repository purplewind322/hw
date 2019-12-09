#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteSymbol(char *str, int *n, int symbolNumber){
    for (int i = symbolNumber; i < *n; i++){
        str[i] = str[i+1];
    }
    *n -=1;
}

int main(){
    int n;
    char symbol[2] = " ";
    printf("Enter n: \n");
    scanf("%d ",&n);
    char *str = new char [n+1];

    printf("Enter stroke \n");
    fget(str);
    for(int i = 0; str[i]; i++){
        if (str[i] == symbol[0] && str[i+1] == symbol[0]){
            deleteSymbol(str, &n, i);
            i--;
        }
    }
    puts(str);


}
