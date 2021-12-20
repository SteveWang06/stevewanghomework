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
	int aveScore = 0;
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
			for(int i = 0; i < n; i++){
				if(id == data[i].id){
					printf("%s", data[i].id)
					printf("%s", data[i].name)
					printf("%s", data[i].score1)
					printf("%s", data[i].score2)
					printf("%s", data[i].score3)
				}
			}
			
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
			for(int i = 0;i < n;++i){
        		for(int j = i+1; j < n;++j){
        			aveScore = (data[i].score1 + data[i].score2 + data[i].score3)/3;
            		if(a[i].aveScore > a[j].aveScore){
                		tmp = a[i];
                		a[i] = a[j];
                		a[j] = tmp;
					}
				}
			}
		}
		esle if(input == 'a'){
			for(int i = 0;i < n;++i){
        		for(int j = i+1; j < n;++j){
        			aveScore = (data[i].score1 + data[i].score2 + data[i].score3)/3;
            		if(a[i].aveScore < a[j].aveScore){
                		tmp = a[i];
                		a[i] = a[j];
                		a[j] = tmp;
                	}
            	}
            }
		}
		esle if(input == 'b'){
			for(int i = 0; i < 0; i++){
				aveScore = (data[i].score1 + data[i].score2 + data[i].score3)/3;
				printf("%.2f", aveScore)
			}
			
		}
		esle if(input == 'q'){
			puts("quit");
		}
		esle{
			puts("error");
			
		}
	}
}

