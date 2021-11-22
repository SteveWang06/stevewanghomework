#include<stdio.h>		
	
int main(){

	char arr[10];
	int first,sum;
	int num[] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	sum = 0;
	first = num[arr[0] - 'A'];
	sum = (first % 10) * 9 + first / 10;
	for(int i = 0; i < 10; i++)
	{
		scanf("%c", &arr[i]);
	}
	for(int i = 1;i < 9; i++)
	{
    	sum = sum + (arr[i] - '0') * (9 - i);
    }
    sum = sum + (arr[9] - '0');
    if (sum % 10 == 0)
	{
    	printf("%s", "CORRECT!!!");         
	}
	else
	{
    	printf("%s", "WRONG!!!"); 
	}
}
