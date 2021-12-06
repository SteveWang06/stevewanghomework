#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[500];
	char c[500];
	char *strt;
	scanf("%s%s", &str, &c);
	strt = strtok(str, c);
	while(strt != NULL){
		printf("%s\n", strt);
		strt = strtok(NULL, c);
	}
	
}
