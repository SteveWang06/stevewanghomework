#include<stdio.h>
#include<string.h>



typedef struct student{
	
	char id[50];
	char name[50];
	int score1[50];
	int score2[50];
	int score3[50];
	
	
} Student;




int main(){
	char n;
	scanf("%d", &n);
	Student data[n];
	for(int i = 0; i < n; i++){
		scanf("%s", data[i].id);
		scanf("%s", data[i].name);
		scanf("%d", &data[i].score1);
		scanf("%d", &data[i].score2);
		scanf("%d", &data[i].score3);
	}
	
	while (1){
		scanf(" %c", input);
		if(input == 'f'){
			
			
		}
		else if(input == 's'){
			for(int i = 0; i < n; i++){
				printf("%s", data[i].id);
				printf("%s", data[i].name);
				printf("%d", &data[i].score1);
				printf("%d", &data[i].score2);
				printf("%d", &data[i].score3);
	}
			
		}
		else if(input == 'd'){
			mediumScore = (data.score1 + data.score2 + data.score3)/3;
			for(int i = 0;i < n;++i){
        		for(int j = i+1; j < n;++j){
            		if(a[i].mediumScore > a[j].mediumScore){
                		tmp = a[i];
                		a[i] = a[j];
                		a[j] = tmp;
			
		}
		esle if(input == 'a'){
			mediumScore = (data.score1 + data.score2 + data.score3)/3;
			for(int i = 0;i < n;++i){
        		for(int j = i+1; j < n;++j){
            		if(a[i].mediumScore < a[j].mediumScore){
                		tmp = a[i];
                		a[i] = a[j];
                		a[j] = tmp;
		}
		esle if(input == 'b'){
			
		}
		esle if(input == 'q'){
			puts("quit");
		}
		esle{
			puts("error");
			
		}
	}
}










