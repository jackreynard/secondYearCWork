/*Accepted 42377*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **table;
	int n, m, i, j, largest, x;
	
	//scans in size of grid and number of adjacent
	//numbers to compare
	scanf("%d" "%d", &n, &m);
	
	//assigns memory to store table
	table = malloc(n * sizeof(int*));
	
	//nested for loops to read in the grid of numbers
	//and allocates the memory to store table
	for (i=0;i<n;i++)
	{
		table[i] = malloc(n * sizeof(int));
		for(j=0;j<n;j++)
		{
			scanf("%d", &table[i][j]);
		}
	}
	
	largest=0;
	
	//first two nested for loops are used to
	//cycle through each element on the grid that will 
	//be compared to four adjacent elements
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		
			int total=0;
			
			//for loop to check any numbers to the right
			//of the coordinates in the above for loops 
			//it repeats for m times
			for(x=0;x<m;x++)
			{
				//if statement to keep pointer within
				//grid and increase total if it is
				if(j+x<n)
				{
					total+=table[i][j+x];
				}
			}	
			//updates largest to total if it is larger
			if(total>largest)
			{
				largest=total;
			}

			//resets total to 0
			total=0;
			//for loop to check any numbers to the left and down
			//of the coordinates in the above for loops 
			//it repeats for m times
			for(x=0;x<m;x++)
			{
				//if statement to keep pointer within
				//grid and increase total if it is
				if((i+x<n)&&(j-x>-1))
				{
					total+=table[i+x][j-x];
				}
			}
			//updates largest to total if it is larger
			if(total>largest)
			{
				largest=total;
			}
			
			//resets total
			total=0;
			//for loop to check any numbers to the right and down
			//of the coordinates in the above for loops 
			//it repeats for m times
			for(x=0;x<m;x++)
			{
				//if statement to keep pointer within
				//grid and increase total if it is
				if((i+x<n)&&(j+x<n))
				{
					total+=table[i+x][j+x];
				}
			}
			//updates largest to total if it is larger
			if(total>largest)
			{
				largest=total;
			}
			
			//resets total
			total=0;
			//for loop to check any numbers directly down
			//of the coordinates in the above for loops 
			//it repeats for m times
			for(x=0;x<m;x++)
			{
				//if statement to keep pointer within
				//grid and increase total if it is
				if(i+x<n)
				{
					total+=table[i+x][j];
				}
			}
			//updates largest to total if it is larger
			if(total>largest)
			{
				largest=total;
			}	
		}
	}
//prints the largest sum
printf("%d",largest);
//frees memory allocated to table
free(table);
}