/*Accepted 40757*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declares the comparison function
typedef int (*compfn)(const void*, const void*);

//creates the structure date, so I can store different types of variables as one
struct date
{
	int month;
	int day; 
	int year;    
};

//array to store the months, that can then be compared to the users month to get an integer value
char* months[]= 
{
	"January", "February",
	"March", "April",
	"May", "June",
	"July", "August",
	"September", "October",
	"November", "December"
};

//function to assign the users month to the equivalent integer
//passes in the users month
int getMonth(char tempMonth[])
{
	int i;
	//for loop to cycle through the months array
	for(i=0;i<12;i++)
	{
		//if statement to see if the users month and the month you want match
		//if they do then return the array number
		if(strcmp(tempMonth, months[i])==0)
		{
			return i;
		}
	}
}

//function used to sort dates that passes in two structs of date
int sortDates(struct date *date1, struct date *date2)
{
	//temp variables to allow for the manipulation
	//of the years without changing 
	//their actual value
	int temp1, temp2;
	
	//if statement that sees if the year is before 2000
	//if it is, then it is assigned a negative number so to keep the
	//dates in descending order
	if(date1->year>15)
	{
		temp1=date1->year -100;
	}
	//if the date's after 200
	//then the value is unchanged
	else
	{
		temp1=date1->year;
	}
	
	//if statement that sees if the year is before 2000
	//if it is, then it is assigned a negative number so to keep the
	//dates in descending order
	if(date2->year>15)
	{
		temp2=date2->year -100;
	}
	//if the date's after 200
	//then the value is unchanged
	else
	{
		temp2=date2->year;
	}
	
	//comparison of the two years
	//if the first year is smaller then they are swapped around 
	if (temp1<temp2)
	{
		return 1;
	}
	
	//comparison of the two years
	//if the first year is larger then they are unchanged
	else if (temp1>temp2)
	{
		return -1;
	}
	
	//if the years are the same then we must compare the months
	else if (temp1==temp2)
	{
	
		//comparison of the two months
		//if the first month is smaller then they are swapped around 
		if (date1->month<date2->month)
		{
			return 1;
		}
		
		//comparison of the two months
		//if the first month is larger then they are unchanged
		else if (date1->month>date2->month)
		{
			return -1; 
		}
		
		//if the months are the same then we must compare the days
		else if (date1->month==date2->month)
		{
			
			//comparison of the two days
			//if the first day is smaller then they are swapped around 
			if (date1->day<date2->day)
			{
				return 1;
			}
			
			//comparison of the two days
			//if the first day is larger then they are unchanged 
			else if (date1->day>date2->day)
			{
				return -1;
			} 
			
			//if the days are the same
			//then the entire date is the same
			//therefore the dates are not swapped
			else
			{
				return 0;
			}
		}
	}
}

int main()
{ 
	int n;
	int i;
	char tempMonth[255]; //temp to read in the users month 
	scanf("%d", &n); //scans in the amount of dates to be entered

	struct date *list;//creates struct date called list of variable size
	struct date *item;//creates struct date called item of variable size

	list = (struct date *)malloc(((n+1) * sizeof(struct date)));//dynamic memory allocation to assign memory for list
	
	//for loop to read in the amount of dates
	//but also the date the user wants to search
	//hence the n+1
	for(i=0; i<n+1; i++)
	{
		scanf("%s %d %d", tempMonth, &list[i].day, &list[i].year);
		list[i].month = getMonth(tempMonth);//assigns the users month to its integer value
	}

	qsort(list, n, sizeof(struct date), (compfn)sortDates);//calls the qsort method to sort the dates
	item =  bsearch (&list[n], list, n , sizeof(struct date), (compfn)sortDates);//calls the bsearch method to find if the users date exists
   
   //for loop to print out the dates in descending order
	for(i=0; i<n; i++)
	{							//prints out the string of the month
								//instead of its corresponding integer
		printf("%s %d %02d\n", months[list[i].month] ,list[i].day, list[i].year);
	}
	
	//if statement that prints out whether the
	//search date exists or not
	if(item != NULL) 
	{
		printf("Yes");
	}
	else 
	{
		printf("No");
	}
	
	//frees the memory allocated to list
	free(list);
}