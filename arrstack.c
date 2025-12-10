#include <stdlib.h>
#include <stdio.h>

#define SIZE 50

int push(int, int ,int* count, int* stack);//returns new top
int pop(int*, int*, int* stack);//returns poped number
int peek(int, int*stack);//returns peeked number
int displaystack(int, int* stack);   //returns 0 or 1

int main(){
	int stack[SIZE];
	int top = -1;
	int count = 0;
	int secim;
	int a;
	
	while(10){
		
		scanf("%d",&secim);
		switch(secim){
			case 1:
				scanf("%d",&a);
				top = push(a,top, &count, stack);
				printf("%d pushlandi\n", a);
				break;
			case 2: 
				int poped = pop(&top, &count, stack);
				printf("%d poplandi\n", poped);
				break;
			case 3:
				printf("stackin en ustundeki sayi %d\n", peek(top, stack));
				break;
			case 4: 
				displaystack(count, stack);
				break;
			case 5:
				return 1;
			
			}
		}
	return 0;
}

int push(int number, int top, int* count, int* stack) {
	
	stack[++top] = number;
	++(*count);
	return top;
}

int pop(int* top, int* count, int*stack){
	if (*top<0){
		printf("listede eleman yok");
		return -1;
	
	}else{
		int tmp = stack[*top];
		--*top;
		--*count;
		return tmp;
	}

}

int peek(int top, int* stack){
	return stack[top];


}

int displaystack(int count, int* stack){
	for (int i=0; i<count; i++){
		printf("%d   ", stack[i]);
	}
	printf("\n");


}
