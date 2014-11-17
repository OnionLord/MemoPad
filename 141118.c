#include<stdio.h>
#include<malloc.h>
#include<string.h>


typedef struct stack *stackPointer;
typedef struct stack {
 int data;
 stackPointer link;
 };
stackPointer top;

int tp = 0;

void push (int item); // add item to the stack
int pop (); // remove top element from the stack

void push(int item)
{
	stackPointer a;
	a = (stackPointer)malloc(sizeof(struct stack));
	a->data = item;
	a->link = top;
	top = a;
	tp++;
}

int pop()
{
	int value;
	stackPointer a;
	
	a = top;

	value = top->data;
	top = top->link;
	
	//printf("%d %d\n", a->data, top->data);
	free(a);

	tp--;
	return value;
}


int main(void)
{

	char c;
	char f;
	int n;
	stackPointer last = top;
	stackPointer temp;
	
	while(1)
	{
		printf("%d : ", tp);
		scanf("%c", &c);
		fflush(stdin);
		if(c == 'a')
		{
	
			if (tp > 10)
			{
				printf("Full!!\n");
			}
			else
			{
				scanf("%c", &f);
				fflush(stdin);
				push((int)f);
			}
		}
		else if(c == 'b')
		{
			if(tp < 1)
			{
				printf("EMPTY!!!!!\n");
			}
			else
			{
				printf("%d is poped\n",pop());
			}
		}
		else if (c == 'c')
		{
			
			while(1)
			{
				if(last == top)
				{
					break;
				}
				printf("%c ", top->data);
				temp = top;
				top = top->link;
				free(temp);
			}
			break;
		}
	}

	return 0;
}
