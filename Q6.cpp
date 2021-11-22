#include<stdio.h>

int main(){
	int arr[10], i = 0;
	char val;
	while(i < 10){
		scanf("%s", &val);
		if(val != 'X'){
			arr[i] = val - '0';
		}
		else{
			arr[i] = val - 78;
		}
		i++;
	}
	while(i < 2){
		for(int j = 1; j < 10; j++){
			arr[j] = arr[j - 1] + arr[j];
		}
		i++;
	}
	
	if(arr[9] % 11 == 0){
		printf("%s", "YES");
	}
	else{
		printf("%s", "NO");
	}
	
}









/* #include<stdio.h>

int main(){
	int arr[10];
	char input;
	for(int j = 0; j < 10; j++){
		scanf("%s", &input);
		if(input != 'X'){
			arr[j] = input - '0';
		}
		else{
			arr[j] = input - 78;
		}
	}
	for(int k = 0; k < 2; k++){
		for(int j = 1; j < 10; j++){
			arr[j] = arr[j - 1] + arr[j];
		}
	}
	
	if(arr[9] % 11 == 0){
		printf("%s", "YES");
	}
	else{
		printf("%s", "NO");
	}
}*/
