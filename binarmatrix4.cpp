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
    int n;
    bool hasNullStr = false;
    unsigned mask = 0;
    mask = ~mask;
    char vector[33];
    scanf("%d",&n);
    getchar();
    unsigned int* B = new unsigned int [n];


    for(int i = 0; i < n; i++){
        gets(vector);
        B[i] = binar_to_int(vector);
    }
    for(int i = 0; i < n && !hasNullStr ; i++){
        if( (B[i]&mask) == 0) {
            hasNullStr = true;
        }
    }
    if(hasNullStr){
        printf("+");
    }else{
        printf("-");
    }

}