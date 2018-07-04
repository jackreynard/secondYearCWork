/*Accepted 43983*/
#include <stdio.h>
#include <string.h>

//creates structure priority that allows me to store the two 
//int values
struct priority
{
	int x;
	int y;
}*priArray;//declares priArray of struct priority


int main()
{
	
	int i, length, point, numX, priY;
	char c;
	char word[6]; //array to store Insert or Pop
	length=0;
	
	//while loop that will go until
	//the first character is read
	while(1)
	{
		//assigns the first character of Pop or
		//Insert to c
		c=getchar();
		
		//if c is I or P then this segment of
		//code will run
		if (c=='I'|| c=='P')
		{
			//scans the remaining part of Insert or Pop
			scanf("%s", &word);
			//if the user is inserting then this runs
			if(strcmp(word, "nsert")==0)
			{
				point=0;//sets the pointer in the queue to 0
				//scans the number and priority
				scanf("%d %d", &numX, &priY);	
				//increases the length of the queue
				length++;
				//reallocates the memory used to store the queue by 1
				//this will happen each time a new item is read in
				priArray=realloc(priArray,(length+1) * sizeof(struct priority));

				//if the queue is empty
				//the item is placed at the start
				if(length==1)	
				{
					priArray[point].y=priY;
					priArray[point].x=numX;
				}	
				else
				//runs if queue is longer than 1
				{
					//scans along the entire queue 
					for(i=0;i<length-1;i++)
					{
						//if the priority of the item to be entered
						//is less than the priority of the item in that 
						//place in the queue, the pointer is increased
						//this finds the items queue position
						if(priY<=priArray[i].y)
						{
							point++;
						}
					}
					
					//if the the item shouldn't be placed last
					//in the queue then we have to move the queue
					if(point!=length-1)	
					{
						//move the memory to allocate space for the item
						//by shifting everything lower than this point down one
						//leaving space for the new item and it is inserted
						memmove(priArray+(point+1),priArray+point,(length - point) * sizeof(struct priority));
						priArray[point].x=numX;
						priArray[point].y=priY;
					}
					else
					//places item at the end of the list
					{
						priArray[length-1].x=numX;
						priArray[length-1].y=priY;
					}
				}
			}
			//code for Popping the queue
			if(strcmp(word, "op")==0)
			{
				//if the queue is empty then return -1
				if(length<=0)
				{
					printf("-1\n");
				}
				else
				{
					
					//prints the value that is popped
					printf("%d\n", priArray[0].x);
					
					//decreases the queue length by 1
					length--;
					
					//moves all the items in the queue below this
					//point up by 1
					memmove(priArray, priArray+1, length * sizeof(struct priority));
					
				}
			}
		}
		//if the end of file is reached then leave while loop
		if(c==EOF)
		{
			break;
		}
	}
	//frees the memory assigned to priArray
	free(priArray);
}