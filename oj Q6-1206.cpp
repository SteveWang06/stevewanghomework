#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[500], c;
	scanf("%[^\n]", str);
	for(int i = 0; i < strlen(str); i++){
		if(islower(str[i])){
			printf("%c", toupper(str[i]));
		}
		else{
			printf("%c", tolower(str[i]));
		}
		
	}
}
