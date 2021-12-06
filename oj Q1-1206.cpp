#include <math.h>
#include <stdio.h>

int is_prime(int n) {
    if (n < 2){
        return 0;
	}else{
	    for (int i = 2; i <= sqrt(n); i++){
	        if (n % i == 0)
	            return 0;
		}
	    return 1;
	}
}

int main(void) {
    int num;
    scanf("%d", &num);

    for (int i = 2; i <= num / 2; i++){
        if (is_prime(i) && is_prime(num - i)){
            printf("%d+%d\n", i, num - i);
    	}
	}
}
