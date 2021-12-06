#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[50], c;
	scanf("%[^\n]", &str);
	for(int i = 0; i < strlen(str); i++){
		c = tolower(str[i]);
		printf("%c", c);
	}
}

