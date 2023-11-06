#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char *string = malloc(1000 * sizeof(char));
    gets(string);
    int len;
    len = strlen(string);
    int *array = malloc(len * sizeof(int));
    for(int i=0; i < len ;++i)
        *(array + i) = 0;
    for(int i=0; i < len; ++i){
        int j=0;
        int count = 1;
        for(int j=0; j < len; ++j){
            if(*(string + i) == *(string + j)){
                *(array + j) = *(array + j) + 1;
                count = 0;
                break;
            }
        }
        for(int j=0; *(array + j) != 0; ++j);
        if(count == 1)
            *(array + j) = *(array + j) + 1;
    }
    for(int i=0; i < len; ++i){
        for(int j=0 ;j < i; ++j){
            if(*(string + i) < *(string + j) && *(array + i) == *(array + j)){
                char c;
                int n;
                n = *(array + i);
                *(array + i ) = *(array + j);
                *(array + j) = n;
                c = *(string + i);
                *(string + i) = *(string + j);
                *(string + j) = c;
            }
            else if(*(array + i)>*(array + j)){
                char c;
                int n;
                n = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = n;
                c = *(string + i);
                *(string + i) = *(string + j);
                *(string + j) = c;
            }
        }
    }
    for(int i = 0; i < len; ++i){
        if(*(array + i) != 0)
            printf("'%c' => %d\n", *(string + i), *(array + i));
    }
    return 0;
}