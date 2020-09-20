#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Array
{
	int A[10];
	int length;
	int size;
};

//struct Array
//{
//	int *A;
//	int length;
//	int size;
//};

void Display(struct Array arr)
{
	int i;
	for(i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
	printf("\n");	
}

void Append(struct Array *arr, int x)
{
	if(arr->length < arr->size)
		arr->A[arr->length] = x;	
	arr->length++;	
}

void Insert(struct Array *arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for(i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i-1];
		arr->A[i] = x;
		arr->length++;
	}
}

int Delete(struct Array *arr, int index)
{
	int i;
	int x = arr->A[index];
	if(index >= 0 && index < arr->length)
	{
		int i;
		for(i = index; i < arr->length; i++)
			arr->A[i] = arr->A[i+1];
		arr->length--;
		return x;	
	}
	return 0;
}

int LinearSearch(struct Array arr, int key)
{
	int i;
	for(i = 0; i < arr.length; i++)
		if(arr.A[i] == key)
			return i;
	return -1;
}

int main(int argc, char *argv[]) 
{
	struct Array arr = {{1,2,3,4,5}, 5, 10};
	
	int x = LinearSearch(arr, 4);
	printf("%d", x);
//	struct Array arr;	
//	arr.size = 10;
//	arr.A = (int *)malloc(sizeof(int)*arr.size);
//	//Darr.A = {1, 2, 3, 4, 5};
//	arr.A[0] = 0;
//	arr.A[1] = 1;
//	arr.A[2] = 2;
//	arr.length=3;	
//	free(arr.A);
	printf("\n");
	return 0;
}
