/*Accepted 32333*/
#include <stdio.h>
#include <math.h>

int main()
{
	int x, i, j, div, car, sum;
	
	//scans in the power to raise 2 to
	scanf("%d", &x);
	int power[x];
	
	//allocates how big the array will be
	memset( power, 0, x*sizeof(int));
	
	//sets the initial value of the array to 1
	power[0] = 1;
	
	//outer for loop to count along all the digits of the integer
	//once one of the inner loops is completed, the pointer moves
	//on to the next digit and the process repeats
	for(i = 0; i < x; i++)
	{
		div=0;
		car=0;
		j=0;
		//while loop for doubling 2
		while(j<x)
		{
			//if statement for whether the previous pass had its value doubled to more than 9
			//if it did then if goes here, if it was less than or equal to 9, it goes to the else
			if(car!=0)
			{	
				//new value for power[j]
				power[j]=(power[j]*2) + car;
				//div value set by taking modulus of power[j] by 10
				div=power[j]%10;
				//car value set by dividing power[j] by 10 to remove the least bit digit
				car=power[j]/10;
				power[j]=div;
            }
			else
			{
				//new value for power[j]
				power[j]=power[j]*2;
				//if the new value is more than 9,
				//then there will be carry value and
				//must have modulus and div 10
				if (power[j]>9)
				{
					div=power[j]%10;
					car=power[j]/10;
					power[j]=div;
				}
			}
			j++;

		}

	}
	sum=0;
	//sum adds the all the values of all power[j]
	for(i=0; i<x; i++)
	{
		sum=sum+power[i];	
	}
	//prints sum
	printf("%d",sum);
}