#include<stdio.h>
int main()
{
	int sum=0,n;
	int a=0;
    int b=1;
    printf(" enter the nth value:");
    scanf("%d",&n);
    printf("fibnocci seies:");
    while(sum<=n)
    {
    	printf("%d",sum);
    	a=b;
    	b=sum;
    	sum=a+b;
	}
	return 0;
}
