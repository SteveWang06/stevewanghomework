#include<stdio.h>
#include<string.h>
#include<ctype.h>

void change(char *str, char *c1, char *c2 ){
	for(int i = 0; i <= strlen(str); i++){
		if(str[i] == c1[0]){
			str[i] = c2[0];
		}
	}
}

void output(char *str, char *c1, char *c2){
	for(int i = 0; i <= strlen(str); i++){
		printf("%c", str[i]);
	}
}

int main(){
	char str[500], c1[500], c2[500];
	scanf("%[^\n]", &str);
	scanf("%s%s", &c1, &c2);
	change(str, c1, c2);
	output(str, c1, c2);
}
