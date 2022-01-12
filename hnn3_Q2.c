#include <stdio.h> 
#include <stdlib.h> 

void printArr(int *arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d", arr[i]);
}

void auxArray(int *aux, queue_t * queue0, queue_t* queue1, queue_t queue2, int* top)
{
	while(!isEmpty(queue0))
		aux[(*top)++] = queue_dequeue(queue0);
	
	while(!isEmpty(queue1))
		aux[(*top)++] = queue_dequeue(queue1);

	while(!isEmpty(queue2))
		aux[(*top)++] = queue_dequeue(queue2);
}

int compareAsc(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}

int compareDesc(const void* a, const void* b)
{
	return *(int*)a < *(int*)b;
}

int findMaxMultupleOf3(int *arr, int size)
{
	qsort(arr, size, sizeof(int), compareAsc);
	
	queue_t* queue0 = queue_create(size);
	queue_t* queue1 = queue_create(size);
	queue_t* queue2 = queue_create(size);

	int i, sum;
	for (i = 0, sum = 0; i < size; i++) {
		sum += arr[i];
		if((arr[i] % 3) == 0)
			queue_enqueue(queue0, arr[i]);
		else if ((arr[i] % 3) == 1)
			queue_enqueue(queue1, arr[i]);
		else
			queue_enqueue(queue2, arr[i]);
	}
	
	if ((sum % 3) == 1) {
		if(!isEmpty(queue1))
			queue_dequeue(queue1);
		else {
			if(!isEmpty(queue2))
				queue_dequeue(queue2);
			else
				return 0;
			
			if (!isEmpty(queue2))
				queue_dequeue(queue1);
			else
				return 0;
		}
	}
	
	else if ((sum % 3) == 2) {
		if (!isEmpty(queue2))
			queue_dequeue(queue2);
		
		else {
			if (!isEmpty(queue1))
				queue_dequeue(queue1);
			else
				return 0;
		
			if (!isEmpty(queue1))
				queue_dequeue(queue1);
			else
				return 0;
		}
	}
	
	int aux[size], top = 0;
	
	auxArray(aux, queue0, queue1, queue2, &top);
	
	qsort(aux, top, sizeof(int), compareDesc);
	
	printArr(aux, top);
	
	return top;
}

int main()
{
	int arr[] = {8, 1, 7, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	if (findMaxMultupleOf3(arr, size) == 0)
		printf("Not Possible");
	
	return 0;
	
} 
