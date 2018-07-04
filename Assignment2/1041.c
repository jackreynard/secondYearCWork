/*Accepted 29824*/

#include <stdio.h>


int main()
{
	int n, m, p, i, j, k, sum;
	//reads in the values for the matrices
	scanf("%d" "%d" "%d", &n, &m, &p);
	//the first matrix
	int table1[n][m];
	//stores the matrices on the heap
	double (*A)[m] = malloc(sizeof(double[n][m]));
	//reads in the values for the matrix, 
	//going across first, then down
	for (i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d", &table1[i][j]);
		}
	}
	
	//the second matrix
	int table2 [m][p];
	//reads in the values for the matrix, 
	//going across first, then down
	for (i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
				scanf("%d", &table2[i][j]);
		}
	}
	
	//assigns the sum of the current row to 0
	sum=0;
	//the matrix for the product
	int finalTable[n][p];
	//multiplies the top left of both matrices together
	//it then moves the counter on to multiply all the values together
	for (i=0;i<n;i++)
    {
		//loop for reading along columns of table2
		for (j=0;j<p;j++)
		{
			//loop for reading along the rows of columns of table1 and 
			//the rows of table2
			for (k=0;k<m;k++)
			{
				sum=sum+table1[i][k]*table2[k][j];
			}
			//the sum for the top left value of the product matrix
			// is assigned to sum. Sum is then reset and the process of multiplying through repeats
			finalTable[i][j]=sum;
			sum=0;
		}
    }
	//prints out the matrix to desired format
	//for loop for reading down the columns
	for (i=0;i<n;i++)
    {
		//for loop for reading across the rows
		for (j=0;j<p;j++)
		{
			//if the counter is here
			//then the value is printed in the top left corner of the matrix
			if ((j!=p-1)&&(i!=n-1))
			{
				printf("%d ", finalTable[i][j]);
			}
			//if the counter is here
			//the value is printed in the bottom left corner
			else if ((j!=p-1)&&(i=n-1))
			{
				printf("%d ", finalTable[i][j]);
			}
			//if the counter is here
			//the value is printed in the right most column but not in the bottom row
			else if((j=p-1)&&(i!=n-1))
			{
				printf("%d\n", finalTable[i][j]);
				
			}
			//if the counter is here
			//the value is printed in the bottom right corner
			else
			{
				printf("%d", finalTable[i][j]);	
			}
		}
			
	}
}