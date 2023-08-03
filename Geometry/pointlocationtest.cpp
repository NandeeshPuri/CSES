#include<stdlib.h>
#include<stdio.h>
 
int main()
{
	long long int t, x1, y1, x2, y2, x3, y3;
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3);
		
		long long int A_x = x2 - x1;
		long long int A_y = y2 - y1;
		long long int P_x = x3 - x1;
		long long int P_y = y3 - y1;
		
		long long int AXP = A_x * P_y - A_y * P_x;
		if(AXP > 0)
			printf("LEFT\n");
		else if(AXP < 0)
			printf("RIGHT\n");
		else
			printf("TOUCH\n");
	}
	
	return 0;
}