#include<stdio.h>  

int main()  
{  
    int a[13], n, m, i;
    scanf("%d%d",&n, &m);  
    for(i=0; i<=13; i++)  
    {  
        a[i]=n % m;  
        n=n / m;  
    }  
    
    for(i = i-1; i >= 0; i--)  
    {  
        printf("%d\n", a[i]);  
    }  
}