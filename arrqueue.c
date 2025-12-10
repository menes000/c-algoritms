//queue nin circular arrey implemantsyonu ve bir bosluk birakilmis yapi front pointeri bosu gosteriyor

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//returns 0 or 1
int enqueue(int* queue, int number, int* rear, int front){
	int tmp = *rear;
	*rear = (*rear+1)%(MAX+1);

	if (front == *rear) {
		*rear = tmp;
		printf("liste dolu\n");
	       	return 0;
	}
	queue[*rear] = number;
	return 1;
}

//returns 0 or 1
int dequeue(int* queue,int rear, int* front){
	if(*front == rear){
		printf("liste bos islem yapilamadi\n");
		return 0 ;
	}
	printf("%d sayisi kaldiriliyor\n", queue[(*front+1)%(MAX+1)]);
	*front = (*front+1)%(MAX+1);
	return 1;


}

void display(int* queue, int rear, int front){
	if(rear==front){
	
		printf("liste bos\n");
		return;

	}
			
	while(front!=rear){
		front = (front+1)%(MAX+1);
		printf("%d  ", queue[front]);
		
	}
	printf("\n");
}

int main(){
	int queue[MAX+1];
	int rear =0, front=0, choice=0, a=0;

	
	while(1){
	scanf("%d", &choice);
		switch(choice){
			case 1:
				scanf("%d", &a);
				if (enqueue(queue, a, &rear, front)) 
					printf("%d basariyla queue nin sonuna eklendi\n",a);
				break;
			case 2:
				dequeue(queue, rear, &front);
				break;
			case 3:
				display(queue, rear, front);
				break;
			
		}	

	}

	return 0;
}
