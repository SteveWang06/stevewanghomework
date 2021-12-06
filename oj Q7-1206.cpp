#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 
int main(){
    char str[101][101], tmp[101];
    int i, j, n=0, max=0;
    while (gets(tmp)!= NULL){
        if (tmp == '\0')
            break;
        else{
            for (i=0; i<101; i++){
                if (i < strlen(tmp))
                    str[n][i]=tmp[i];
                else
                    str[n][i]=' ';
            }
            n++;
            if (strlen(tmp)> max)
                max=strlen(tmp);
        }
    }
    for (i=0; i<max; i++){
        for (j=n-1; j>=0; j--)
            printf("%c", str[j][i]);
        if (i < max-1)
            printf("\n");
    }
    return 0;
}


