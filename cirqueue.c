# include<stdio.h>
# include<conio.h>
# define max 10
void main()
{
	int cqueue[max], data;
	int front, rear, reply, option;
	front = rear = 0;
	do
	{
		printf("\n C Language program to implement basic operations on a Circular Queue \n");
		printf("\n 1. Insert number in a Circular Queue");
		printf("\n 2 .Delete number from Circular Queue");
		printf("\n 3. Exit \n");
		printf("\n Select option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1 : 
				printf("\n Enter number: ");
				scanf("%d", &data);
				reply = insq(cqueue, &front, &rear, &data);// By Akshat Sharma (cse001)
				if(reply == -1)
					printf("\n Circular Queue is Full \n");
				else
					printf("\n Number %d is inserted in a Circular Queue \n", data);
				break;
			case 2 : 
				reply = delq(cqueue, &front, &rear,&data);
				if(reply == -1)
					printf("\n Circular Queue is Empty \n");
				else
					printf("\n %d is deleted from Circular Queue \n", data);
					printf("\n");
				break;
			case 3 : exit(0);
		} // By Akshat Sharma (cse001)
	}while(1);
} 
int insq(int cqueue[max], int *front, int *rear, int *data)
{
	if((*rear + 1) % max == *front)
		return(-1);
	else
	{
		*rear = (*rear + 1) % max;
		cqueue[*rear] = *data;
		return(1);
	}
}
int delq(int cqueue[max], int *front, int *rear, int *data)
{// By Akshat Sharma (cse001)
	if(*front == *rear)
		return(-1);
	else
	{
		*front = (*front + 1) % max;
		*data = cqueue[*front];
		return(1);
	}
}
