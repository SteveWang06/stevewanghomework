#include<stdio.h>
int main()
{
    int n,i, count[10];
    scanf("%d",&n);

    for(i=2; i<=n; i++)
    {  
        while(n % i == 0)
        {
            printf("%d ",i);
            n/=i;
            count[i];
        }
    }
    if (count[i] == 0)
    {
        printf("%s","NO");
    }
    
    
    return 0;
}