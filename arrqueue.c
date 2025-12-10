//queue nin circular arrey implemantsyonu

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

int dequeue(int* queue, int number, int rear, int* front){
	


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
		}
	}

	return 0;
}
