#include <stdio.h>
#include <cstring>

unsigned int binar_to_int(char *str){
    unsigned int vector = 0, mask = 1;

    for(int i = strlen(str)-1; i >= 0; i--,mask<<=1){
        if(str[i] == '1'){
            vector |= mask;
        }
    }
    return vector;
}
void int_to_binar(unsigned int vector,char *str) {
    unsigned int mask = 1;
    for (int i = 31; i >= 0; mask <<= 1, i--) {
        if (vector & mask) {
            str[i] = '1';
        }else{
            str[i] = '0';
        }
    }
}

int main(){
    unsigned int X = 0,Y = 0,mask = 1;
    char vectorX[33];
    char vectorY[33];
    vectorY[32] = '\0';

    printf("Enter X:\n");
    gets(vectorX);
    X = binar_to_int(vectorX);

    for(int i = 0; i < 32; i++){
        if(i%2){
            Y |= (mask & X)<<i;
            X>>=1;
        }
    }
    int_to_binar(Y,vectorY);
    puts(vectorY);


}