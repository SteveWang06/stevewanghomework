#include<stdio.h>


void input(int *arr, int size){
	for(int i = 0; i <= size - 1; i++){
		scanf("%d", &arr[i]);
	}
}

int check(int *arr, int size, int x){
	int count = 0;
	for(int i = 0; i < size - 1; i++){
		if(arr[i] == x){
			count = i + 1;
		}
		
	}
	if(count > 0){
		printf("%d position.", count);
	}
	else{
		printf("%s", "none");
	}
}



int main(){
	int arr[100], size, x;
	scanf("%d", &size);
	input(arr, size);
	scanf("%d", &x);
	check(arr, size, x);
	
}

