#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str;
	scanf("%c", &str);
	if(str >= 'A' && str <= 'Z'){
		puts("uppercase");
	}
	else if(str >= 'a' && str <= 'z'){
		puts("lowercase");
	}
	else{
		puts("special character");
	}
}
