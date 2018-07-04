/*Accepted 28168*/

#include <stdio.h>
#include <string.h>

#define LENGTH 100

int main()
{	
	
	int amount1, amount2, i, j, k, sentence_length;
	//array used to assign values during bubblesort
	char temp[LENGTH];
	scanf("%d" ,&amount1);
	//array for reading in the first set of strings
	char sentence1[amount1][LENGTH];
	//dynamically assigned array
	char *group1[amount1];
	
	for (i=0;i<amount1;i++)
	{
		//scans in the string and then bubblesorts them based on length
		scanf("%s", sentence1[i]);
		for(k=0; k<amount1-1; k++)
		{
			for(j=0; j<amount1-k-1; j++)
			{
				if(strlen (sentence1[j])<strlen(sentence1[j+1]))
				{
					//strcpy copies string from second item to first item
					//eg: sentence1[j] to temp
					strcpy (temp,sentence1[j]);
					strcpy (sentence1[j],sentence1[j+1]);
					strcpy (sentence1[j+1],temp);
				}
			}
		}
	}
	//a for loop to assign the values of the original array
	//to the dynamically assigned array
	for (i=0;i<amount1;i++)
	{
		sentence_length=strlen(sentence1[i]);
		group1[i]=malloc(sentence_length*sizeof(char));
		strcpy(group1[i],sentence1[i]);
		
	}
	
	scanf("%d" ,&amount2);
	//array for reading in the second set of strings
	char sentence2[amount2][LENGTH];
	//dynamically assigned array
	char *group2[amount2];
	
	for (i=0;i<amount2;i++)
	{
		//scans in the string and then bubblesorts them based on length
		scanf("%s", sentence2[i]);
		for(k=0; k<amount2-1; k++)
		{
			for(j=0; j<amount2-k-1; j++)
			{
				if(strlen (sentence2[j])<strlen (sentence2[j+1]))
				{
					//strcpy copies string from second item to first item
					//eg: sentence2[j] to temp
					strcpy (temp,sentence2[j]);
					strcpy (sentence2[j],sentence2[j+1]);
					strcpy (sentence2[j+1],temp);
				}
			}
		}
	}
	//a for loop to assign the values of the original array
	//to the dynamically assigned array
	for (i=0;i<amount2;i++)
	{
		sentence_length=strlen(sentence2[i]);
		group2[i]=malloc(sentence_length*sizeof(char));
		strcpy(group2[i],sentence2[i]);
	
	}

	//sets counters to 0
	j = k = 0;
	//finds total amount of strings entered to get length of sorted array
	int amount=amount1+amount2;
	//dynamically assigned array
	char *group3[amount];
	char  sorted[amount][LENGTH];
	//merge algorithm to merge both arrays given
	for (i = 0; i <amount;i++) 
	{	
	//if the j counter has reached the amount of strings entered then k is assigned to the sorted array
	 if (j==amount1)
			{
				strcpy(sorted[i], group2[k]);
				k++;
			}
			//if the j counter has reached the amount of strings entered then k is assigned to the sorted array
			else if (k==amount2)
			{
				strcpy(sorted[i], group1[j]);
				j++;
			}
			//if the length of the first string in the first array
			//is larger than the first string of the second array
			//then the first item in the sorted array is from the first array 
			else if (strlen(group1[j]) > strlen(group2[k])) 
			{
				strcpy(sorted[i], group1[j]);
				//moves pointer j along one so to compare the next element of sentence1 
				//with the current element of sentence2
				j++;
			}
			//if the length of the first string in the second array
			//is larger than the first string of the first array
			//then the first item in the sorted array is from the second array
			else if (strlen(group2[k]) > strlen(group1[j]))
			{
				strcpy(sorted[i], group2[k]);
				//moves pointer k along one so to compare the next element of sentence2 
				//with the current element of sentence1
				k++;
			}	
	}
	
	//a for loop to assign the values of the original array
	//to the dynamically assigned array
	// and prints out the sorted array
	for (i=0;i<amount;i++)
	{
		sentence_length=strlen(sorted[i]);
		group3[i]=malloc(sentence_length*sizeof(char));
		strcpy(group3[i],sorted[i]);
		printf("%s\n", group3[i]);
	}
}
//frees the memory allocated
free(group1);
free(group2);
free(group3);