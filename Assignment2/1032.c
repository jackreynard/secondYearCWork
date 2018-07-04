/*Wrong Answer 32273*/

#include <stdio.h>
int main()
{
	int i, j, counter, length;
	char string1[10000];
	char string2[10000];
	char string3[10000];
	char *s;
	//reads in the three strings, including any empty spaces
	scanf("%[^\n]%*c", &string1);
	scanf("%[^\n]%*c", &string2);
	scanf("%[^\n]%*c", &string3);
	
	//method to find the length of the strings
	int strlen(char *s)
	{
		length=0;
		//while loop to increase the length and move s pointer along
        while(*s!='\0')
        {
            length++;
            s++;
        }
        return length;
    }
	//counter variable
	j=0;
	
	//variable to see how many times a substring appears 
    counter=0;
	
	//for loop to compare the first and second string
	for(i=0; i<strlen(string1); i++)
	{
		//if character in string1[i] equals string2[j] 
		//then move to next if
		//if it doesn't then go to else
		if(string1[i]==string2[j])
        {
			//if j and length of string2-1 are the same, 
			//increase counter and reset j
			if(j==strlen(string2)-1)
			{
				counter++;
				j=0;   
            }       
        }
		else
		{
			j = 0;
		}
		j++;
    }
	//prints counter
    printf("%d ",counter);
    
	//repeats the above method, except compares string1 and string3
	j = 0;
    counter=0;
	for(i = 0;i<strlen(string1);i++)
	{
		if(string1[i]==string3[j])
        {
			if(j==strlen(string3)-1)
			{
				counter++;
				j = 0;   
            }       
        }
		else
		{
			j = 0;
		}
		j++;
    }
    printf("%d",counter);
}
