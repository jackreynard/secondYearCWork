/*Accepted 28020*/

#include <stdio.h>

#define ROTATE 3
int main()
{
	int i;
	//loop to read all characters and rotate as required
	//and assigns the char to its ASCII value
	while((i=getchar())!=EOF)
	{
		//if statement for all values that are between
		//A and W, and all values between a and w
		//it then adds the rotate number defined above
		if ((i>='A' && i<='W')||(i>='a' && i<='w'))
		{
			i=i+ROTATE;
		}
	
		//if statement for all values that are between
		//X and Z, and all values between x and z
		//it then minuses the difference to the start of the alphabet 
		else if ((i>='X' && i<='Z')||(i>='x'&& i<='z'))
		{
			i-=(26-ROTATE);
		}
		//if statement for all other characters 
		//that will keep their same value
		else
		{
			i=i;
		}
		//prints out the new string
		putchar(i);
	
	}	
}