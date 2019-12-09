#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int countWordsInStr(char *str){
    int count = 0;
    for (int i = 0; str[i]; i++){
        if(str[i] == ',' || str[i] == '.'){
            count++;
        }
    }
    return (count);
}

bool isDublicate(char *str, char c, int cNumber) {
    for (int i = 0; str[i]; i++){
        if (str[i] == c && i != cNumber){
            return true;
        }
    }
    return false;
}


int main(){

    int wordCount = 0, seqLenght;
    int wordStart = 0,wordEnd = 0;

    printf("Enter sequence lenght:\n");
    scanf("%d",&seqLenght);
    getchar();






    char *wordsSequence =  new char [seqLenght];
    gets(wordsSequence);
    wordCount = countWordsInStr(wordsSequence);
    char **wordsArray = new char* [wordCount];






    for (int i = 0,count = 0,wordIndex = 0; wordsSequence[i]; i++){
        count++;
        if(wordsSequence[i] == ','|| wordsSequence[i] == '.'){
            wordsArray[wordIndex] = new char [count];
            wordEnd = i;
            for (int j = wordStart, k = 0; j <= wordEnd; j++,k++){
                wordsArray[wordIndex][k] = wordsSequence[j];
            }
            wordsArray[wordIndex][count - 1] = '\0';
            wordIndex++;
            wordStart = i+1;
            count = 0;
        }
    }

    for(int i = 0; i < wordCount-1; i++) {

        if(strcmp(wordsArray[i],wordsArray[wordCount-1]) != 0){
            bool symbolsHasDublicates = true;
            for(int j = 0; j < strlen(wordsArray[wordCount-1]) && symbolsHasDublicates; j++){
                symbolsHasDublicates = isDublicate(wordsArray[i],wordsArray[i][j],j);
            }
            if(symbolsHasDublicates){
                puts(wordsArray[i]);
            }
        }

    }





    delete[] wordsSequence;
    for(int i = 0; i < wordCount; i++){
        delete[] wordsArray[i];
    }
    delete [] wordsArray;

    printf("\n");
    system("pause");
}

